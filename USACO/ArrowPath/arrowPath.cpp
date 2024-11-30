#include <bits/stdc++.h>
using namespace std;
const int bigNum = 2 * pow(10, 5);
int n;
char grid [bigNum][2];
bool visited [bigNum][2];
string ans = "NO";
int final_dest(int x, int y){
    if (grid[x][y] ==  '>'){
        return x + 1;
    } else {
        return x - 1;
    }
}
void dfs(int x, int y){
    //start at (, )
    if (visited[x][y]) { return; }
    visited[x][y] = true;
    if (y == 1 && x == n - 1){
        ans = "YES";
    }
    if (y != 0){ //possible to go up
        int tx = final_dest(x, 0);
        dfs(tx, 0);
    }
    if (x != 0){ //possible to go left
        int tx = final_dest(x-1, y);
        dfs(tx, y);
    }
    if (x != n - 1){ //possible to go right
        int tx = final_dest(x + 1, y);
        dfs(tx, y);
    }
    if (y != 1){ //possible to down
        int tx = final_dest(x, 1);
        dfs(tx, 1);
    }
}
void solve(){
    
    cin >> n;
    for (int x = 0; x < 2; x++){
        for (int i = 0; i < n; i++){
            cin >> grid[i][x];
        }
    }
    dfs(0, 0);
    cout << ans << "\n";
    ans = "NO";
    memset(visited, 0, sizeof(visited));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}