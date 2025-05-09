#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
const ll m = 998244353;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
//got the fucking idea
//my inability to dp really fucked me
//got bent over 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    ll t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <ll> dp(4, 0);
        dp[0] = 1;
        for (ll i = 0; i < n; i++){
            int a;
            cin >> a;
            if (a == 2) dp[a] = (dp[a] + dp[a])%m;
            dp[a] = (dp[a] + dp[a - 1])%m;
        }
        cout << dp[3] << "\n";
        
    }
}