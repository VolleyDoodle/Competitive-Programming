#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int n, x;
    cin >> n >> x;
    vector <int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    vector <int> dp(x + 1, 0);
    dp[0] = 1;
    for (int coin : coins){
        for (int i = 0; i <= x; i++){
            if (coin + i > x) continue;
            dp[i + coin]+=dp[i];
            dp[i + coin]%=mod;
        }
    }
    cout << dp[x];
}