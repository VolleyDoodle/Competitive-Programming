#include <bits/stdc++.h>
using namespace std;
//represent weighted graph w/ pairs (.first = node points to and .second = weight)
vector <vector <pair <int, int>>> graph;
vector <bool > visited;
int k, curAns = 0;
void dfs(int node){
    visited[node] = true;
    for (auto curNode : graph[node]){
        if (!visited[curNode.first] && curNode.second >= k){
            curAns++;
            dfs(curNode.first);
        }
    }
}
int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    graph.resize(n + 1); visited.resize(n + 1);
    for (int i = 0; i < n - 1; i++){
        int n1, n2, w1;
        cin >> n1 >> n2 >> w1;
        graph[n1].push_back({n2, w1});
        graph[n2].push_back({n1, w1});
    }
    for (int i = 0; i < q; i++){
        fill(visited.begin(), visited.end(), 0);
        curAns = 0;
        int v; cin >> k >> v;
        dfs(v);
        cout << curAns << "\n";
    }
}