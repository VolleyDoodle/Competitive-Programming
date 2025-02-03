//go from outside to inside#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
const int num = 1503;
int n;
string grid[num][num];
int ans = 0;
//10/15 test cases (pretend contest)
void ff(int i, int j, int curAmt, vector <vector <int>>& count){
    //look to the left and up
    //if to the left, there is a right then ff there
    //if up there is a down, then ff from there
    /*if (i == n|| j == n){
        ans += (curAmt - 1) * (stoi(grid[i][j]));
        return;
    }*/
    //count[i][j] = curAmt;
    if (j >= 1 && grid[i][j - 1] == "R" && count[i][j - 1] != curAmt){
        ans += curAmt - count[i][j - 1];
        count[i][j - 1] = curAmt;
        ff(i, j - 1, curAmt, count);
    } if (i >= 1 && grid[i - 1][j] == "D" && count[i - 1][j] != curAmt){
        ans+= curAmt - count[i - 1][j];
        count[i - 1][j] = curAmt;
        ff(i - 1, j, curAmt, count);
    }
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector <vector <int>> count(n + 1, vector <int>(n + 1, 0));
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        string c;
        cin >> c;
        for (int j = 0; j < n; j++){
            grid[i][j] = s[j];
        }
        grid[i][n] = c;
        count[i][n] = stoi(c);
        
    }
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        grid[n][i] = s;
        count[n][i] = stoi(s);
    }
    int q;
    cin >> q;
    
    ans = 0;
    for (int x = 0; x < n; x++){
        int cur = stoi(grid[x][n]);
        ff(x, n, cur, count);
    }
    for (int i = 0; i < n; i++){
        int cur = stoi(grid[n][i]);
        ff(n, i, cur, count);
    }
    /*for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans += count[i][j];
        }
    }*/
    cout << ans << "\n";
    while(q--){
        int i , j;
        cin >> i >> j;
        i--; j--;
        
        ans -= count[i][j];
        if (grid[i][j] == "D"){
            grid[i][j] = "R";
            count[i][j] = count[i][j + 1];
        }
        else{
            grid[i][j] = "D";
            count[i][j] = count[i + 1][j];
        }
        ans += count[i][j];
        if (count[i][j + 1]  != count[i + 1][j]){
            ff(i, j, count[i][j], count);
        }
        
        cout << ans << "\n";
    }
}