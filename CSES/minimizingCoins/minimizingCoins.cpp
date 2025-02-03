#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> dp, coins;
int solve(int num){
    if (num == 0) return 0;
    if (dp[num] != INT_MAX){
        return dp[num];
    }
    for (int coin : coins){
        if (coin > num) continue;
        if (dp[num - coin] == INT_MAX){
            dp[num - coin] = solve(num - coin);
        }
        dp[num] = min(dp[num], 1 + dp[num - coin]);
    }
    return dp[num];
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int n, x;
    cin >> n >> x;
    coins.resize(n);
    dp.resize(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) cin >> coins[i];
    //sort(coins.begin(), coins.end(), greater<int>());
    //recursion hella slow
    //solve(x);
    for (int i = 0; i <= x; i++){
        for (int coin : coins){
            if (i + coin <= x){
                dp[i + coin] = min(dp[i + coin], 1 + dp[i]);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
}