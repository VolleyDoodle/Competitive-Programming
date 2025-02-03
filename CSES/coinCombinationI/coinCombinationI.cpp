#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    ll n, x;
    cin >> n >> x;
    vector <ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];
    vector <ll> dp(x + 1, 0);
    dp[0] = 1;
    for (ll i = 0; i <= x; i++){
        for (ll coin : coins){
            if (i + coin > x) continue;
            dp[i + coin]+= dp[i];
            dp[i + coin]%=mod;
        }
    }
    cout << dp[x];
}