#include <bits/stdc++.h>
using namespace std;
//tree cuz n - 1 edges
vector <vector <int>> tree;
vector <int> barnVal;
vector <bool> visited;
int sum = 0, avg;
void dfs(int node){
    visited[node] = true;
    for (int curNode: tree[node]){
        if (barnVal[curNode])
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    tree.resize(n + 1); barnVal.resize(n + 1); visited.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> barnVal[i];
        sum+=barnVal[i];
    }
    avg = sum/n;
    for (int i = 0; i < n - 1; i++){
        int t, tt; cin >> t >> tt;
        tree[t].push_back(tt); tree[tt].push_back(t);
    }
    for (int i = 1; i <= n; i++){
        if (barnVal[i] > avg){
            dfs(i);
        }
    }

}