#include <bits/stdc++.h>
#define ll long long
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
    //where n = 21 364 ms
    //runs in O(n^2 * 2^n)
    int n;
    cin >> n;
    vector <vector <int>> grid(n, vector <int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    vector <int> dp(1 << n, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //want to add "j"
            if (grid[i][j]){
                for (int s = 0; s < (1 << n); s++){
                    if (__popcount(s) == i && ((s & (1 << j)) == 0)){
                        dp[s ^ (1 << j)] += dp[s];
                        dp[s ^ (1 << j)] %= m;
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1];
}