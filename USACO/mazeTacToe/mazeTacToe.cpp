#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> grid;
vector <pair <int, int>> moves;
void dfs(int row, int col, vector <vector <bool>>& visited){
    if (grid[row][col + 1] == -1){
        
    }
    if (grid[row][col - 1] == -1){
        
    }
    if (grid[row + 1][col] == -1){
        
    }
    if (grid[row - 1][col] == -1){
        
    }


    if (grid[row][col + 1] >= 0){
            
    }
    if (grid[row][col - 1] >= 0){
        
    }
    if (grid[row + 1][col] >= 0){
        
    }
    if (grid[row - 1][col] >= 0){
        
    }
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n;
    cin >> n;
    grid.resize(n, vector<char>(n));
    int moveIndex = 0;
    pair <int, int> start;
    for (int i = 0; i < n; i++){
        for (int x = 0; x < n; x++){
            string t1 = "";
            for (int t = 0; t < 3; t++){
                char t2;
                t1+=t2;
            }
            if (t1 == "...") grid[i][x] = -1;
            else if (t1 == "###") grid[i][x] = -2;
            else if (t1 == "BBB"){
                grid[i][x] = -1;
                start.first = i;
                start.second = x;
            }
            else grid[i][x] = moveIndex++;
        }
    }
    vector <vector <bool>> visited(n, vector<bool>(n));
    dfs(start.first, start.second, visited);

}