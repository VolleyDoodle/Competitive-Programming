#include <bits/stdc++.h>
using namespace std;
vector <vector <string>> grid;
vector <int> dirX = {0, 0, 1, -1};
vector <int> dirY = {1, -1, 0, 0};
bool valid = true;
int pow3(int p){
    int cur = 1;
    while (p > 0){
        cur*=3;
        p--;
    }
    return cur;
}
vector <char> base3(int num){
    //vector should be 9 long
    vector <int> ans(9, 0);
    int idx = 0;
    while (num > 0){
        ans[idx] = num%3;
        num/=3;
        idx++;
    }
    vector <char> rV(9);
    for (int i = 0; i < 9; i++){
        if (ans[i] == 0) rV[i] = '.';
        else if (ans[i] == 1) rV[i] = 'M';
        else rV[i] = 'O';
    }
    return rV;
}
int winningGame(vector <char> game){
    //stupid ass method for checking if a grid (game) is winning
    //check by row, col then diagonals
    //col
    int amt = 0;
    for (int i = 0; i < 3; i++){
        string cur = "";
        for (int j = i; j < 9; j+=3){
            //i + j
            cur += game[j];
        }
        if (cur == "MOO" || cur == "OOM") amt++;
    }
    //row
    for (int i = 0; i < 9; i+=3){
        string cur = string(1, game[i]) + game[i + 1] + game[i + 2];
        if (cur == "MOO" || cur == "OOM") amt++;
    }
    //diagonal
    string cur = string(1, game[0]) + game[4] + game[8];
    //cout << cur;
    if (cur == "MOO" || cur == "OOM") amt++;
    cur = string(1, game[2]) + game[4] + game[6];
    if (cur == "MOO" || cur == "OOM") amt++;
    return amt;
}
void dfs(int i, int j, vector <char>& potGame, vector <vector <bool>>& visited, vector <char>& game){
    visited[i][j] = true;
    if (grid[i][j] != "..." && grid[i][j] != "BBB"){
        //it can be 0 -> any num
        //but not 1 - > any num
        int before = winningGame(potGame);
        //some instruction here
        //lets see if its usefull at all
        int idx = 3 * (grid[i][j][1] - '1') + (grid[i][j][2] - '1');
        if (grid[i][j][0] == game[idx] || (potGame[idx] == game[idx] && game[idx] != '.')) potGame[idx] = game[idx];
        else return;
        /*int after = winningGame(potGame);
        if (before != after && before != 0){
            valid = false;
            return;
        }
        if (before != after) return;*/
    }
    
    visited[i][j] = true;
    for (int x = 0; x < 4; x++){
        if (!visited[i + dirX[x]][j + dirY[x]] && grid[i + dirX[x]][j + dirY[x]] != "###"){
            dfs(i + dirX[x], j + dirY[x], potGame, visited, game);
        }
    }
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, ans = 0;
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
    //have some 3^9 * 25^2 time compleixty
    //just brute force through all grids, then dfs to see if possible to make that grid
    //only care about the grids that actually result in a poitn so probably faster
    //O...O.OOM
    vector <char> game2 = {'O', '.', '.', '.', 'O', '.', 'O', 'O' , 'M'};
    /*vector <char> potGame(9, '.');
    vector <vector <bool>> visited(n, vector<bool>(n, false));
    if (winningGame(game)){
        cout << "h";
    }
    dfs(sI, sJ, potGame, visited, game);
    cout << "h";*/
    //int amt = 0;
    //set <vector <
    cout << winningGame(game2);
    for (int i = 0; i < pow3(9); i++){
        vector <char> game = base3(i);
        if (winningGame(game)){
            //amt++;
            //cout << "winning pos";
            valid = true;
            vector <vector <bool>> visited(n, vector<bool>(n, false));
            vector <char> potGame(9, '.');
            dfs(sI, sJ, potGame, visited, game);
            if (potGame == game && valid){
                
                cout << "game : " << "\n";
                for (int x = 0; x < 3; x++){
                    for (int y = 0; y < 3; y++){
                        cout << game[x * 3 + y];
                    }
                    cout << "\n";
                }
                cout << "pot game : \n";
                for (int x = 0; x < 3; x++){
                    for (int y = 0; y < 3; y++){
                        cout << potGame[x * 3 + y];
                    }
                    cout << "\n";
                }
                ans++;
            }

        }
    }
    //cout << "amt: " << amt;
    cout << ans;


}