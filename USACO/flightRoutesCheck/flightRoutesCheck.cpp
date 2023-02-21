#include <bits/stdc++.h>
using namespace std;
// two solutions
//one with O(n^2) (dfs each airport and see)
//other with 0(n) reverse flights and start from any node
//first check if node[i] can reach all other nodes with normal
//and if node[i] can reach all other airports with reversed then all airports can reach node[i];

vector <vector <int>> graph;
vector <vector <int>> rgraph;
vector <bool> visited;
void dfs(int node){
    for (int curNode: graph[node]){
        if (!visited[curNode]){
            visited[curNode] = true;
            dfs(curNode);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    graph.resize(n + 1); rgraph.resize(n + 1); visited.resize(n + 1);

    for (int i = 1; i <= m; i++){
        int t, tt; cin >> t >> tt;
        graph[t].push_back(tt);
        rgraph[tt].push_back(t);
    }
    //since from "any" we can auto use port 1 as "root"
    visited[1] = true;
    dfs(1);
    //now check for unvisited airports from 1
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cout << "NO\n" << 1 << " " << i;
            return 0;
        }
    }
    graph = rgraph;
    fill(visited.begin(), visited.end(), 0);
    //same thing w/ reverse
    visited[1] = true;
    dfs(1);
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cout << "NO\n" << i << " " << 1;
            return 0;
        }
    }
    cout << "YES";
}