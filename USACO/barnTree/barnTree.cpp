#include <bits/stdc++.h>
using namespace std;
struct orders{
    int barnFrom, barnTo;
    long long hayAmt;
};
vector <long long> subtreeSum;
vector <vector <int>> barns;
vector <bool> visited;
vector <orders> ans;
int avg;
void dfsSubTreeSum(int node){
    subtreeSum[node]-=avg;
    visited[node] = true;
    for (int nextNode : barns[node]){
        if (!visited[nextNode]){
    
            dfsSubTreeSum(nextNode);
            subtreeSum[node]+=subtreeSum[nextNode];
        }
    }

}
void dfsAns(int node){
    //child to parent
    visited[node] = true;
    for (int nextNode : barns[node]){
        if (!visited[nextNode]){
            if (subtreeSum[nextNode] >= 0){
                dfsAns(nextNode);
            }
            if (subtreeSum[nextNode] > 0){
                ans.push_back({nextNode, node, subtreeSum[nextNode]});
            }
        }
        
    }
    //parent to node
    for (int nextNode : barns[node]){
        if (!visited[nextNode] && subtreeSum[nextNode] < 0){
            ans.push_back({node, nextNode, -subtreeSum[nextNode]});
            dfsAns(nextNode);
        }
    }
}
int main(){
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    long long sum = 0;
    cin >> n;
    subtreeSum.resize(n + 1); barns.resize(n + 1);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), 0);
    for (int i = 1; i <= n; i++){
        cin >> subtreeSum[i];
        sum+=subtreeSum[i];
    }
    avg = sum/n;
    for (int i = 0; i < n - 1; i++){
        int t, tt;
        cin >> t >> tt;
        barns[t].push_back(tt);
        barns[tt].push_back(t);
    }
    dfsSubTreeSum(1);
    fill(visited.begin(), visited.end(), 0);
    dfsAns(1);
    cout << ans.size() << '\n';
    for (orders curOrder : ans){
        cout << curOrder.barnFrom << " " << curOrder.barnTo << " " << curOrder.hayAmt << '\n';
    }
}   