#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
int curId, ans;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void gdfs(int cur, vector <int>& ids, vector <vector <int>>& ggraph){
    ids[cur] = curId;
    for (int nxtNode : ggraph[cur]){
        if (ids[nxtNode] == 0){
            gdfs(nxtNode, ids, ggraph);
        }
    }
}
void fdfs(int cur, vector <bool>& visited, vector <int>& ids,  vector <vector <int>>& fgraph){
    visited[cur] = true;
    for (int nxtNode : fgraph[cur]){
        if (!visited[nxtNode]){
            if (ids[cur] != ids[nxtNode] || ids[cur] == 0){
                ans++;
            } else fdfs(nxtNode, visited, ids, fgraph);
            
        }
    }
}
void fdfs2(int cur, vector <bool>& visited, vector <int>& ids, vector <vector <int>>& fgraph){
    visited[cur] = true;
    for (int nxtNode : fgraph[cur]){
        if (!visited[nxtNode] && ids[nxtNode] == ids[cur]){
            fdfs2(nxtNode, visited, ids, fgraph);
        }
    }
}
void solve(){
    int n, m1, m2;
    curId = 0;
    ans = 0;
    cin >> n >> m1 >> m2;
    vector <vector <int>> fgraph(n + 1), ggraph(n + 1);
    for (int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        fgraph[u].push_back(v);
        fgraph[v].push_back(u);
    }
    for (int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        ggraph[u].push_back(v);
        ggraph[v].push_back(u);
    }
    vector <int> ids(n + 1, 0);
    for (int i = 1; i <= n; i++){
        if (!ggraph[i].empty() && ids[i] == 0){
            curId++;
            gdfs(i, ids, ggraph);
        }
    }
    //now all nodes are marked with id to connected componenet
    //traverse through f graph, 
    vector <bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            fdfs(i, visited, ids, fgraph);
        }
    }
    fill(visited.begin(), visited.end(), false);
    //only dfs in the same id :)
    for (int i = 1; i <= n; i++){
        if (!visited[i] && !ggraph[i].empty()){
            ans++;
            fdfs2(i, visited, ids, fgraph);
        }
    }
    cout << (ans - curId);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    //dont wanna make excuses but this problem was worded so fucking badly
    //and the problem statement just dont make sense sometimes
    //maybe i just dont know english tho???
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}
