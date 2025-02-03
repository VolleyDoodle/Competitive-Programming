#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void dfs(vector <vector <int>>& graph, vector <int>& vis, int curNode, int curDist){
    ans = max(ans, curDist);
    vis[curNode]++;
    for (int nxt : graph[curNode]){
        if (vis[nxt] == 1) dfs(graph, vis, nxt, curDist + 1);
    }
}
void solve(){
    ans = 0;
    int n;
    cin >> n;
    vector <vector <int>> graph(n + 1), rgraph(n + 1);
    vector <int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++){
        int r;
        cin >> r;
        graph[i].push_back(r);
        rgraph[r].push_back(i);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            //do bfs
            queue <int> q1;
            set <int> s;
            q1.push(i);
            while (!q1.empty()){
                int cur = q1.front(); q1.pop();
                s.insert(cur);
                vis[cur]++;
                for (int nxt : graph[cur]){
                    if (!vis[nxt]){
                        q1.push(nxt);
                    } else if (vis[nxt] && s.count(nxt)){
                        //frickin cycle
                        queue <int> q2;
                        q2.push(nxt);
                        while (!q2.empty()){
                            int cur2 = q2.front(); q2.pop();
                            vis[cur2]++;
                            if (vis[graph[cur2][0]] == 1) q2.push(graph[cur2][0]);
                        }
                    }
                }
            }
        }
    }
    //now all nodes in a cycle are marked with vis[i] = 2;

    for (int i = 1; i <= n; i++){
        if (vis[i] == 2){
            //now use reverse graph adn see farthest dist
            dfs(rgraph, vis, i, 0);
        }
    }
    cout << ans + 2;
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}