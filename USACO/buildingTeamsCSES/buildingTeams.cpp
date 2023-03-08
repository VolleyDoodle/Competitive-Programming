#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> graph;
vector <bool> visited, check;

void dfs(int node){
    visited[node] = true;
    for (int curNode: graph[node]){
        if (!visited[curNode]){
            check[curNode] = !check[node];
            dfs(curNode);
        } else if (check[curNode] == check[node]){
            cout << "IMPOSSIBLE";
            exit(0);
        }
        
        
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1); visited.resize(n + 1); check.resize(n + 1);
    for (int i = 0; i < m; i++){
        int t, tt; cin >> t >> tt;
        graph[t].push_back(tt);
        graph[tt].push_back(t);
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            check[i] = true;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++){
        cout << check[i] + 1 << " ";
    }

}