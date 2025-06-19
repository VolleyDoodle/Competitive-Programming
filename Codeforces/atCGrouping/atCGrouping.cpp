#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int n;
    cin >> n;
    vector <ll> dp(1 << n, 0);
    vector <vector <int>> grid(n, vector <int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    //basically group till i
    //runs in O(n^2 * 2^n)
    /*for (int s = 0; s < (1 << n); s++){
        for (int i = 0; i < n; i++){
            if (s & (1 << i)){
                for (int j = i; j < n; j++){
                    if (s & (1 << j)){
                        dp[s] += grid[i][j];
                    }
                }
            }
        }
    }*/
    //should be O(n * 2^n)
    for (int s = 0; s < (1 << n); s++){
        int past = s & (s - 1);
        int rhtmost = log2(s & (-s));
        dp[s] = dp[past];
        for (int i = rhtmost; i < n; i++){
            if (s & (1 << i)){
                dp[s] += grid[rhtmost][i];
            }
        }
    }
    for (int s = 0; s < (1 << n); s++){
        for (int mask = s; mask != 0; mask = (mask - 1) & s){
            dp[s] = max(dp[s], dp[mask] + dp[s ^ mask]);
        }
    }
    cout << dp[(1 << n) - 1];

}