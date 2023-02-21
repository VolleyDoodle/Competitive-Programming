#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> graph;
vector <bool> visited;
int ans = 1, curAns = 1;
void dfs(int i){
   
    for (int j = 0; j < graph[i].size(); j++){
        if (!visited[graph[i][j]]){
            curAns++;
            visited[graph[i][j]] = true;
            dfs(graph[i][j]);
        }
        
    }
}
int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    graph.resize(n + 1); visited.resize(n + 1);
    vector <int[3]> data(n);
    for (int i = 0; i < n; i++){
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j ){continue;}
            int length =pow((data[i][0] - data[j][0]), 2) + pow((data[i][1] - data[j][1]), 2);
            if (length <= pow(data[i][2], 2)){
                graph[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            visited[i] = true;
            dfs(i);
            ans = max(ans, curAns); curAns = 1;
            fill(visited.begin(), visited.end(), 0);
        }
    }
    cout << ans;
}