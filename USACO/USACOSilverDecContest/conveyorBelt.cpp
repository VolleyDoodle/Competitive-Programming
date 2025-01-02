#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int n;
vector<vector<int>> grid;
vector<vector<bool>> good;
vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}}; // Directions: U, D, R, L
int cnt = 0;
void dfs(int i, int j){
    //if this cell is pointing outside or to another good cell
    //then it is good
    if (good[i][j]) return;
    for (int x = 0; x < 4; x++){
        int xOff = dirs[x].f;
        int yOff = dirs[x].s;
        if (grid[i][j] < 4 && x != grid[i][j]) continue;

        if (j + xOff < 0 || j + xOff >= n || i + yOff < 0 || i + yOff >= n){
            good[i][j] = true;
            cnt++;
            break;
        }
        else if (good[i + yOff][j + xOff]){
            good[i][j] = true;
            cnt++;
            break;
        }
    }
    if (good[i][j]){
        for (int x = 0; x < 4; x++){
            int xOff = dirs[x].f;
            int yOff = dirs[x].s;
            if (j + xOff < 0 || j + xOff >= n || i + yOff < 0 || i + yOff >= n){
                continue;
            }
            dfs(i + yOff, j + xOff);
        }
    }


}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int q;
    cin >> n >> q;
    //vector <vector <int>> grid(n, vector <int>(n, 4));
    grid.resize(n, vector <int>(n, 4));
    good.resize(n, vector <bool>(n, false));
    vector <char> dirs = {'U', 'D', 'R', 'L'};
    //in grid, 0 = up, 1 = down, 2 = right, 3 = left, 4 = any
    vector <pair <int, int>> pos(q);
    for (int i = 0; i < q; i++){
        int r, c;
        char t;
        cin >> r >> c >> t;
        r--; c--;
        int index = find(dirs.begin(), dirs.end(), t) - dirs.begin();
        grid[r][c] = index;
        pos[i] = {r, c};
    }
    //the dfs is only dfs to good squares cells
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dfs(i, j);
        }
    }
    vector <int> ans(q);
    for (int i = q - 1; i >= 0; i--){
        ans[i] = (n * n) - cnt;
        grid[pos[i].f][pos[i].s] = 4;
        dfs(pos[i].f, pos[i].s);
    }
    for (int& a : ans){
        cout << a << "\n";
    }


}