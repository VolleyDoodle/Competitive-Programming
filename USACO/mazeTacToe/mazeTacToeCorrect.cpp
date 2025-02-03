#include <bits/stdc++.h>
using namespace std;
vector <vector <string>> grid;
vector <int> dirX = {0, 0, 1, -1};
vector <int> dirY = {1, -1, 0, 0};
bool visited[25][25][19683];
set <string> ans;
//idea is to keep track of visited array, but mark as visited for each state instead
//then just check states?
int pow3(int p){
    int cur = 1;
    while (p > 0){
        cur*=3;
        p--;
    }
    return cur;
}
int base3(string potGame){
    //vector should be 9 long
    int multi = 1, returnAns = 0;
    for (int i = 8; i >= 0; i--){
        returnAns+= multi * (potGame[i] - '0');
        multi*=3;
    }
    return returnAns;
}
int winningGame(string game){
    //stupid ass method for checking if a grid (game) is winning
    //check by row, col then diagonals
    //col
    //M = 1, O = 2, . = 0
    int amt = 0;
    for (int i = 0; i < 3; i++){
        string cur = "";
        for (int j = i; j < 9; j+=3){
            //i + j
            cur += game[j];
        }
        if (cur == "122" || cur == "221") amt++;
    }
    //row
    for (int i = 0; i < 9; i+=3){
        string cur = string(1, game[i]) + game[i + 1] + game[i + 2];
        if (cur == "122" || cur == "221") amt++;
    }
    //diagonal
    string cur = string(1, game[0]) + game[4] + game[8];
    //cout << cur;
    if (cur == "122" || cur == "221") amt++;
    cur = string(1, game[2]) + game[4] + game[6];
    if (cur == "122" || cur == "221") amt++;
    return amt;
}
void dfs(int i, int j, string potGame){
    if (visited[i][j][base3(potGame)]) return;
    if (grid[i][j][0] == 'M' || grid[i][j][0] == 'O'){
        int idx = 3 * (grid[i][j][1] - '1') + (grid[i][j][2] - '1');
        if (potGame[idx] == '0'){
            potGame[idx] = (grid[i][j][0] == 'M' ? '1' : '2');
        }
    }
    visited[i][j][base3(potGame)] = true;
    if (winningGame(potGame)){
        ans.insert(potGame);
        return;
    }
    for (int x = 0; x < 4; x++){
        if (!visited[i + dirX[x]][j + dirY[x]][base3(potGame)] && grid[i + dirX[x]][j + dirY[x]] != "###"){
            dfs(i + dirX[x], j + dirY[x], potGame);
        }
    }
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int n;
    cin >> n;
    grid.resize(n, vector <string>(n));
    int sI, sJ;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            string cell = "";
            for (int x = 0; x < 3; x++){
                char c; cin >> c; cell+=c;
            }
            grid[i][j] = cell;
            if (grid[i][j] == "BBB"){
                sI = i;
                sJ = j;
            }
        }
    }
    string pGame(9, '0');
    dfs(sI, sJ, pGame);
    //cout << "amt: " << amt;
    //2 = 0, 1 = M
    cout << ans.size();


}