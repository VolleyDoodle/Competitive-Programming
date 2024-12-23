#include <bits/stdc++.h>
using namespace std;
const int bigNum = 2e9 + 4;
int middle;
void dfs(int row, int col, vector <vector <bool>>& visited, vector <vector <int>>& grid){
    visited[row][col] = true;
    if (!visited[row][col + 1] && abs(grid[row][col + 1] - grid[row][col]) <= middle){
        dfs(row, col + 1, visited, grid);
    }
    if (!visited[row][col - 1] && abs(grid[row][col - 1] - grid[row][col]) <= middle){
        dfs(row, col - 1, visited, grid);
    }
    if (!visited[row + 1][col] && abs(grid[row + 1][col] - grid[row][col]) <= middle){
        dfs(row + 1, col, visited, grid);
    }
    if (!visited[row - 1][col] && abs(grid[row - 1][col] - grid[row][col]) <= middle){
        dfs(row - 1, col, visited, grid);
    }
    
}
int main(){
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int r, c;
    cin >> r >> c;
    vector <vector <int>> grid(r + 2, vector <int>(c + 2));
    vector <pair <int, int>> waypoints;

    fill(grid[0].begin(), grid[0].end(), bigNum);
    fill(grid[r + 1].begin(), grid[r + 1].end(), bigNum);


    for (int i = 1; i <= r; i++){
        grid[i][0] = bigNum; grid[i][c + 1] = bigNum;
        for (int j = 1; j <= c; j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            int wp;
            cin >> wp;
            if (wp) waypoints.push_back({i, j});
        }
    }
    int high = 1e9, low = 0, ans = 1e9;
    while (low <= high){
        middle = low + (high - low)/2;
        int wpCount = 0;
        vector <vector <bool>> visited(r + 2, vector <bool>(c + 2, false));
        dfs(waypoints[0].first, waypoints[0].second, visited, grid);
        for (auto& wp : waypoints){
            wpCount+=visited[wp.first][wp.second];
        }
        if (wpCount == waypoints.size()){
            high = middle - 1;
            ans = middle;
        } else{
            low = middle + 1;
        }
    }
    cout << ans;
}