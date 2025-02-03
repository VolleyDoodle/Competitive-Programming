#include <bits/stdc++.h>
using namespace std;
const int num = 1503;
int n;
string grid[num][num];
int ans = 0;
//count will store how many have to pass through (i, j)
void ff(int i, int j, int curAmt, vector <vector <int>>& count){

    if (i == n|| j == n){
        count[i][j]+= (curAmt);
        ans += (curAmt * stoi(grid[i][j]));
        //ans += (curAmt - 1) * (stoi(grid[i][j]));
        return;
    }
    if (!count[i][j]) curAmt++;
    count[i][j]+=curAmt;
    if (grid[i][j] == "D"){
        ff(i + 1, j, curAmt, count);
    } else{
        ff(i, j + 1, curAmt, count);
    }
}
void change(int i , int j, int curAmt, vector <vector <int>>& count){
    if (i == n || j == n){
        ans-= count[i][j] * stoi(grid[i][j]);
        count[i][j]+=curAmt;
        ans+= count[i][j] * stoi(grid[i][j]);
        //ans += (curAmt - 1) * (stoi(grid[i][j]));
        return;
    }
    
    count[i][j]+= curAmt;
    if (grid[i][j] == "D"){
        change(i + 1, j, curAmt, count);
    } else{
        change(i, j + 1, curAmt, count);
    }
}

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    vector <vector <int>> count(n + 1, vector <int>(n + 1, 0));
    ans = 0;
    
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if (i!= n && j != n) count[i][j] = 1;
            if (i!=0 && grid[i - 1][j] == "D") count[i][j]+=count[i - 1][j];
            if (j!=0 && grid[i][j - 1] == "R") count[i][j] += count[i][j - 1];
        }
    }
    for (int x = 0; x < n; x++){
        int cur = stoi(grid[x][n]);
        ans += cur * count[x][n];
    }
    for (int i = 0; i < n; i++){
        int cur = stoi(grid[n][i]);
        ans += cur * count[n][i];
    }
    cout << ans << "\n";
    while(q--){
        int i , j;
        cin >> i >> j;
        i--; j--;
        int temp = count[i][j];
        change(i, j, -1 * count[i][j], count);
        if (grid[i][j] == "D") grid[i][j] = "R";
        else grid[i][j] = "D";
        change(i, j, temp, count);
        //changing i, j means the same amt of cows still go through it
        //but now the before is -1, and after will be +1
        cout << ans << "\n";
    }
}