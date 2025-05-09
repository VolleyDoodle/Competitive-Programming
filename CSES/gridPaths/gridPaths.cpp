#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
const int m = 1e9 + 7;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int n;
    cin >> n;
    vector <vector <int>> grid(n, vector <int>(n));
    vector <vector <int>> dp(n, vector <int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            grid[i][j] = (c == '.' ? 1 : 0);
        }
    }
    if (!grid[0][0]){
        cout << 0;
        return 0;
    }
    //1 = empty (can travel), 0 = trap (cant travel)
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dp[i][j]%=m;
            if (i + 1 < n && grid[i + 1][j]){
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j]%=m;
            } 
            if (j + 1 < n && grid[i][j + 1]){
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1]%=m;
            } 
        }
    }
    cout << dp[n - 1][n - 1];
}