#include <bits/stdc++.h>
using namespace std;
int n;
vector <vector <int>> tree;
vector <bool> visited;
void dfs(int node){
    visited[node] = true;
    for (int curNode : tree[node]){
        if (!visited[curNode]){
            dfs(curNode);
        }
    }
}
int main(){
    cin >> n;
    tree.resize(n + 1);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), 0);
    for (int i = 1; i <= n; i++){
        int distantRel;
        cin >> distantRel;
        tree[i].push_back(distantRel);
        tree[distantRel].push_back(i);
        
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans;

}