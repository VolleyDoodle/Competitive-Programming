#include <bits/stdc++.h>
using namespace std;
int graph[1005][1005];
bool visited[1005][1005];
void dfs(int i, int j){
    if (graph[i][j + 1] && !visited[i][j + 1]){
        visited[i][j+1] = true; 
        dfs(i, j + 1);
    }
    if (graph[i][j - 1] && !visited[i][j - 1]){
        visited[i][j-1] = true; 
        dfs(i, j - 1);
    }
    if (graph[i + 1][j] && !visited[i + 1][j]){
        visited[i + 1][j] = true;
        dfs(i + 1, j);
    }
    if (graph[i - 1][j] && !visited[i - 1][j]){
        visited[i - 1][j] = true;
        dfs(i - 1, j);
    }
}
int main(){
    int n, m; cin >> n >> m;
    //O(n * m)
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char t; cin >> t;
            if (t == '.'){graph[i][j] = 1;}
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!visited[i][j] && graph[i][j]){
                visited[i][j] = true;
                ans++;
                dfs(i, j);
            }
        }

    }
    cout << ans;

}