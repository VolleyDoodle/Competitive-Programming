#include <bits/stdc++.h>
using namespace std;
const int num = 1503;
int n;
string grid[num][num];
int ans = 0;

void ff(int i, int j, int curAmt, vector <vector <int>>& count){

    if (i == n|| j == n){
        ans += (curAmt - 1) * (stoi(grid[i][j]));
        return;
    }
    if (count[i][j] == 0){
        curAmt++;
    }
    count[i][j] = curAmt;
    if (grid[i][j] == "D"){
        ff(i + 1, j, curAmt, count);
    } else{
        ff(i, j + 1, curAmt, count);
    }
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        string c;
        cin >> c;
        for (int j = 0; j < n; j++){
            grid[i][j] = s[j];
        }
        grid[i][n] = c;
    }
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        grid[n][i] = s;
    }
    int q;
    cin >> q;
    vector <vector <int>> count(n, vector <int>(n, 0));
    ans = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (!count[x][y]){
                ff(x, y, 1, count);
            }
        }
    }
    cout << ans << "\n";
    while(q--){
        int i , j;
        cin >> i >> j;
        i--; j--;
        if (grid[i][j] == "D") grid[i][j] = "R";
        else grid[i][j] = "D";
        vector <vector <int>> count(n, vector <int>(n, 0));
        ans = 0;
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                if (!count[x][y]){
                    ff(x, y, 1, count);
                }
            }
        }
        cout << ans << "\n";
    }
}