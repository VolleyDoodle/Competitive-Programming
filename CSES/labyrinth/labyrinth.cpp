#include <bits/stdc++.h>
using namespace std;
int n, m, sX, sY, eX, eY;
vector <vector <char>> grid;
vector <vector <bool>> visited;
int ansLen = INT_MAX;
string ansStr = "";
void dfs(string curDir, int x, int y, vector <vector <bool>> visited){
    visited[y][x] = true;
    if (grid[y][x] == 'B'){
        if (curDir.size() < ansLen){
            ansStr = curDir;
            ansLen = curDir.size();
        }
    }
    if (grid[y][x + 1] != '#' && !visited[y][x + 1]){
        dfs(curDir + 'R', x + 1, y, visited);
    }
    if (grid[y][x - 1] != '#' && !visited[y][x - 1]){
        dfs(curDir + 'L', x - 1, y, visited);
    }
    if (grid[y + 1][x] != '#' && !visited[y + 1][x]){
        dfs(curDir + 'D', x, y + 1, visited);
    }
    if (grid[y - 1][x] != '#' && !visited[y - 1][x]){
        dfs(curDir + 'U', x, y - 1, visited);
    }
}
int main(){
    cin >> n >> m;
    grid.resize(n + 2,vector <char>(m + 2, '#'));
    visited.resize(n + 2, vector <bool>(m + 2, false));
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= m; x++){
            cin >> grid[i][x];
            if (grid[i][x] == 'A') {
                sX = x; sY = i;
            }
            else if (grid[i][x] == 'B') {
                eX = x; eY = i;
            }
        }
    }

    dfs("", sX, sY, visited);
    if (ansLen != INT_MAX){
        cout << "YES\n" << ansLen << "\n" << ansStr;
    } else{
        cout << "NO";
    }
}