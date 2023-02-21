#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <vector <int>> graph;
vector <bool> visited;
int visitedNodes;
vector <bool> removed;
void dfs(int node){
    for (int curNode: graph[node]){
        if (!removed[curNode] && !visited[curNode]){
            visited[curNode] = true;
            visitedNodes++;
            dfs(curNode);
        }
    }
}

int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    graph.resize(n + 1); visited.resize(n + 1); removed.resize(n + 1);
    for (int i = 0; i < m; i++){
        int t, tt; cin >> t >> tt;
        graph[t].push_back(tt); graph[tt].push_back(t);
    }
    int node;
    for (int i = 0; i < n; i++){
        for (int x = 1; x <= n; x++){
            if (!removed[x]){node = x; break;}
        }
        visited[node] = true;
        visitedNodes = 1;
        dfs(node);
        int remove; cin >> remove;
        removed[remove] = true;
        fill(visited.begin(), visited.end(), 0);
        string ans = visitedNodes == n - i ? "YES\n" : "NO\n";
        //above line is same as commented code below!!!!
        cout << ans;
        /*if (visitedNodes == n - i){
            //connected
            cout << "YES" << "\n";
            continue;
        }
        cout << "NO" << "\n";*/
        
    }
}