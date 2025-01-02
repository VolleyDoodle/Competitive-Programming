#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n + 1);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector <bool> visited(n + 1, false);
    vector <int> child(n + 1);
    queue <int> nodes;
    nodes.push(1);
    visited[1] = true;
    while (!nodes.empty()){
        int cur = nodes.front();
        nodes.pop();
        for (int node : graph[cur]){
            if (!visited[node]){
                child[node] = cur;
                visited[node] = true;
                nodes.push(node);
            }
        }
    }
    if (!visited[n]){
        cout << "IMPOSSIBLE";
        return 0;
    }
    int ans = 0, cur = n;
    vector <int> vAns;
    
    while (cur != 1){
        vAns.push_back(cur);
        cur = child[cur];
        ans++;
    }
    cout << ans + 1 << "\n";
    vAns.push_back(1);
    for (int i = ans; i >= 0; i--){
        cout << vAns[i] << " ";
    }
    

}