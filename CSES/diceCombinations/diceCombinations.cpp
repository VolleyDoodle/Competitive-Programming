#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int n;
    cin >> n;
    vector <ll> dp(n + 8);
    dp[0] = 1;
    for (int i = 0; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            dp[i + j]+=dp[i]%mod;
            dp[i + j]%=mod;
        }
    }
    cout << dp[n];
}