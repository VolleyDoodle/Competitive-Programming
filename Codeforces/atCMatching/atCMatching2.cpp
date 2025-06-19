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
    //where n = 21
    //runs in O(n * 2^n)
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
    for (int s = 0; s < (1 << n); s++){
        for (int w = 0; w < n; w++){
            //pull dp 224 ms
            /*if (s & (1 << w) && grid[__popcount(s) - 1][w]){
                dp[s]+=dp[s ^ (1 << w)];
                dp[s]%=m;
            }*/
            //push dp 181 ms
            if (((s & (1 << w)) == 0) && grid[__popcount(s)][w]){
                dp[s ^ (1 << w)] += dp[s];
                dp[s ^ (1 << w)]%=m;
            }
        }
    }
    cout << dp[(1 << n) - 1];
}