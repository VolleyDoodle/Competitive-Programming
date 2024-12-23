#include <bits/stdc++.h>
using namespace std;
int gCount, bCount;
void dfs(int row, int col, vector<vector<char>>& grid, vector <vector <bool>>& visited){
    visited[row][col] = true;
    if (grid[row][col] == 'B') bCount++;
    if (grid[row][col] == 'G') gCount++;

    if (grid[row][col + 1] != '#' && !visited[row][col + 1]){
        dfs(row, col + 1, grid, visited);
    }
    if (grid[row][col - 1] != '#' && !visited[row][col - 1]){
        dfs(row, col - 1, grid, visited);
    }
    if (grid[row + 1][col] != '#' && !visited[row + 1][col]){
        dfs(row + 1, col, grid, visited);
    }
    if (grid[row - 1][col] != '#' && !visited[row - 1][col]){
        dfs(row - 1, col, grid, visited);
    }
    
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector <char>> grid(n + 2, vector <char>(m + 2));
    vector <vector <bool>> visited(n + 2, vector <bool>(m + 2, false));
    fill(grid[0].begin(), grid[0].end(), '#');
    fill(grid[n + 1].begin(), grid[n + 1].end(), '#');
    vector <pair <int, int>> bLocs;
    int gAmt = 0;
    for (int i = 1; i <= n; i++){
        grid[i][0] = '#';
        grid[i][m + 1] = '#';
        for (int x = 1; x <= m; x++){
            cin >> grid[i][x];
            if (grid[i][x] == 'B'){
                bLocs.push_back({i, x});
            }
            else if (grid[i][x] == 'G') gAmt++;
        }
    }
    for (auto& bLoc : bLocs){
        int i = bLoc.first; int x = bLoc.second;
        if (grid[i][x + 1] == '.') grid[i][x + 1] = '#';
        if (grid[i][x - 1] == '.') grid[i][x - 1] = '#';
        if (grid[i + 1][x] == '.') grid[i + 1][x] = '#';
        if (grid[i - 1][x] == '.') grid[i - 1][x] = '#';
    }
    gCount = 0;
    bCount = 0;
    if (grid[n][m] == '#'){
        if (gAmt == 0) cout << "YES";
        else cout << "NO";
        return;
    } 
    dfs(n, m, grid, visited);
    if (bCount == 0 && gCount == gAmt){
        cout << "YES";
        return;
    }
    cout << "NO";
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