#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> grid;
int n, k, compNum;
void dfs(int row, int col, int& curComp, vector <vector <int>>& visited){
    compNum++;
    visited[row][col] = curComp;
    if (row + 1 < n && grid[row + 1][col] == grid[row][col] && visited[row + 1][col] == -1){
        dfs(row + 1, col, curComp, visited);
    }
    if (row - 1 >= 0 && grid[row - 1][col] == grid[row][col] && visited[row - 1][col] == -1){
        dfs(row - 1, col, curComp, visited);
    }
    if (col + 1 < 10 && grid[row][col + 1] == grid[row][col] && visited[row][col + 1] == -1){
        dfs(row, col + 1, curComp, visited);
    }
    if (col - 1 >= 0 && grid[row][col - 1] == grid[row][col] && visited[row][col - 1] == -1){
        dfs(row, col - 1, curComp, visited);
    }
}
int main(){
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    
    cin >> n >> k;
    grid.resize(n, vector<int>(10));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            char t;
            cin >> t;
            grid[i][j] = t - '0';
        }
    }

    while (true){
        vector <vector <int>> visited(n, vector<int>(10, -1));
        vector <int> compNums;
        int curComp = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 10; j++){
                if (grid[i][j] == 0) continue;
                if (visited[i][j] == -1){
                    compNum = 0;
                    dfs(i, j, curComp, visited);
                    curComp++;
                    compNums.push_back(compNum);
                }
            }
        }
        bool change = false;
        for (int i = 0; i < 10; i++){
            vector <int> newVec;
            for (int j = n - 1; j >= 0; j--){
                if (grid[j][i] == 0) continue;
                if (compNums[visited[j][i]] < k){
                    newVec.push_back(grid[j][i]);
                    continue;
                }
                change = true;
            }
            int count = 0;
            for (int j = n - 1; j >= n - newVec.size(); j--){
                grid[j][i] = newVec[count++];
            }
            for (int j = n - newVec.size() - 1; j >= 0; j--){
                grid[j][i] = 0;
            }
            
        }

        if (!change) break;
    }

    for (int r = 0; r < n; r++){
        for (int c = 0; c < 10; c++){
            cout << grid[r][c];
        }
        cout << "\n";
    }


}