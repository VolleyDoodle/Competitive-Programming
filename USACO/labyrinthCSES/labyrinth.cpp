#include <bits/stdc++.h>
using namespace std;
bool graph[1005][1005];

pair <int, int> start, endp;
int ans = INT_MAX; string ansS;
void dfs(int i, int j, int curAns, string curAnsS,bool visited[][1005]){
    bool tried = true;
    if (i == endp.first && j == endp.second){
        if (curAns <= ans){
            ans = curAns; ansS = curAnsS;
        }
    }
    curAns++;
    if (graph[i][j + 1] && !visited[i][j + 1]){
        tried = false;
        visited[i][j+1] = true; 
        dfs(i, j + 1, curAns, curAnsS + 'R',visited);
        visited[i][j+1] = false;
    }
    if (graph[i][j - 1] && !visited[i][j - 1]){
        tried = false;
        visited[i][j-1] = true; 
        dfs(i, j - 1, curAns, curAnsS + 'L', visited);
        visited[i][j-1] = false;
    }
    if (graph[i + 1][j] && !visited[i + 1][j]){
        tried = false;
        visited[i + 1][j] = true;
        dfs(i + 1, j, curAns, curAnsS + 'D',visited);
        visited[i + 1][j] = false;
    }
    if (graph[i - 1][j] && !visited[i - 1][j]){
        tried = false;
        visited[i - 1][j] = true;
        dfs(i - 1, j, curAns, curAnsS + 'U',visited);
        visited[i - 1][j] = false;
    }

}
int main(){
    int n, m; cin >> n >> m;
    bool visited[1005][1005];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char t; cin >> t; 
            if (t == '.'){graph[i][j] = 1;}
            else if (t == 'A'){start.first = i; start.second = j; graph[i][j] = 1; visited[i][j] = true;}
            else if (t == 'B'){endp.first = i; endp.second = j; graph[i][j] = 1;}
        }
    }
    dfs(start.first, start.second, 0, "", visited);
    if (ans == INT_MAX){
        cout << "NO";
    } else{
        cout << "YES" << "\n" << ans << "\n" << ansS;
    }
}