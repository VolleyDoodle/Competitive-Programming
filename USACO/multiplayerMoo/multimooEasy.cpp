//horrible problem, so easily done by bruteforce
//actual intended solution is so pointless...
//horrible horrible horrible problem
#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
int n, tempAns = 0;
vector <int> dirX = {1, -1, 0, 0};
vector <int> dirY = {0, 0, 1, -1};
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
bool inGrid(int i, int j){
    if (i < 0 || i >= n || j < 0 || j >= n) return false;
    return true;
}
void ff(int i, int j, vector <vector <int>>& grid, int id1, int id2, vector <vector <bool>>& visited){
    tempAns++;
    visited[i][j] = true;
    for (int x = 0; x < 4; x++){
        int ni = i + dirX[x];
        int nj = j + dirY[x];
        if (inGrid(ni, nj) && (grid[ni][nj] == id1 || grid[ni][nj] == id2) && !visited[ni][nj]){
            ff(ni, nj, grid, id1, id2, visited);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("multimoo");
    int ans = 0;
    cin >> n;
    vector <vector <int>> grid(n, vector <int>(n));
    vector <vector <bool>> visited(n, vector <bool>(n, false));
    vector <int> idCnt;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    //give everthing an id
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //can only check for i - 1 and j - 1
            //bool found = false;
            if (ans >= (n * n)/2) break;
            if (!visited[i][j]){    
                tempAns = 0;        
                ff(i, j, grid, grid[i][j], grid[i][j], visited);
                ans = max(ans, tempAns);
            }
        }
    }
    cout << ans << "\n";
    ans = 0;
    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++){
        for (int j = 1; j < n; j++){
            //can only check for i - 1 and j - 1
            //bool found = false;
            if (ans >= (n * n)/2) break;
            if (!visited[i][j]){    
                tempAns = 0;        
                ff(i, j, grid, grid[i][j - 1], grid[i][j], visited);
                ans = max(ans, tempAns);
                visited.assign(n, vector<bool>(n, false));
            }
        }
    }
    cout << ans << "\n";
}