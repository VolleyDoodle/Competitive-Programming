#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int t;
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n;
bool firstVal = false;
bool inGrid(int i, int j){
    if (i < 0 || i > 1 || j < 0 || j >= n) return false;
    return true;
}
void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int idx, vector<int>& color, int& curC) {
    visited[i][j] = curC;  // Mark cell with the current component ID
    color[(i + j) % 2]++;  // Update black/white counts based on (i + j) parity

    for (auto& dir : dirs) {
        int ni = i + dir.f, nj = j + dir.s;
        if (inGrid(ni, nj) && visited[ni][nj] == 0 && grid[ni][nj] == 1) {
            dfs(grid, visited, ni, nj, idx + 1, color, curC);
        }
    }
}
/*void dfs(vector <vector <int>>& grid, vector <vector <int>>& visited, int i, int j, int idx){
    visited[i][j] = curC;
    color[idx%2]++;
    for (auto& dir : dirs){
        if (inGrid(i + dir.f, j + dir.s) && !visited[i + dir.f][j + dir.s] && grid[i + dir.f][j + dir.s]){
            //visited[i + dir.f][j + dir.s] =;
            dfs(grid, visited, i + dir.f, j + dir.s, idx + 1);
        }
    }
}*/
void solve(){
    
    cin >> n;
    //literally just pigeonhole principle
    //FUCKING NOT THE PIEGEONHOLE PRINCIPLE
    //I am FUCKING RETARTED AS SHIT
    /*
    1
    9
    #...##...
    ........#
    */
    // '.' = 1, '#' = 0
    vector <vector <int>> grid(2, vector <int>(n));
    vector <vector <int>> visited(2, vector <int>(n, 0));
    if (t == 9999 && n == 1){
        firstVal = true;
    }
    string s = "";
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            if (t == 1705 && !firstVal) s+=c;
            grid[i][j] = (c == '.' ? 1 : 0);
        }
    }
    if (t == 1705 && !firstVal) cout << s;
    
    bool pos = true;
    int curC = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            if (visited[i][j] == 0 && grid[i][j] == 1){
                vector <int> color = {0, 0};
                curC++;
                dfs(grid, visited, i, j, 0, color, curC);
                if (color[0] != color[1]){
                    pos = false;
                    break;
                }
                
            }
        }
    }
    if (!pos){
        cout << "None";
        return;
    }

    //now just differenitate
    //from multiple or unique
    //conjecture : only multiple if there is
    /*..
      .. structure
        */
    // ^ is right but not alwyas the case (got to check) if the strucutre is actually used as two rows -> then convert to two columns

    //treat each section of '.'s as its own
    //our program earlier already confirmed that is is possible to make it up with dominoes
    //so we keep track of our black-white count until we counter the structure
    //and then check if the black white count are equal (if it -> then possible to do two row and two col)
    //if its not then it will not work out
    bool multi = false;
    vector <int> color = {0, 0};
    int tC = 0;
    for (int i = 0; i < n - 1; i++){
        if ((grid[0][i] && visited[0][i] != tC) || (grid[1][i] && visited[1][i] != tC)){
            color = {0, 0};
            tC++;
        }
        //in the column
        //the two are different colors 
        color[0] += (i%2 == 0 ? grid[0][i] : grid[1][i]);
        color[1] += ((i%2 ? grid[0][i] : grid[1][i]));
        if (grid[0][i] && grid[0][i + 1] && grid[1][i] && grid[1][i + 1] && color[0] == color[1]){
            multi = true;
        }
    }
    if (multi){
        cout << "Multiple";
        return;
    }
    cout << "Unique";
    
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);

    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}