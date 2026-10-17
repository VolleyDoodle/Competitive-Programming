#include <bits/stdc++.h>
#define ll long long
const ll bigNum = 15e3 + 50;
const ll m = 1e9 + 7;
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    //tbh solution makes hella sense
    //but just kinda confusing behind the llution of j "unfinished" groups
    //like why have this "unfinished" and "finished groups" (should read codeforces blog on it, but the fuckass website is always down!)
    ll n, x;
    cin >> n >> x;
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    //so i basically had the right idea
    //just knowledge blocked / didn't know how to implement
    //let least value coder be si, so contribution is -si, basically can js sum this up for unfinished groups for val of k
    //dp[i][j][k], first i coders, j "unfinished" groups (basically still open to adding), score/penalty of k = stores # of ways to reach all these conditions
    //technically can do 3d dp, with all of n, but pretty much uneeded, so just store two rows (of i - 1 and i)
    vector <vector <ll>> dp1(n, vector <ll>(bigNum, 0));
    vector <vector <ll>> dp2(n, vector <ll> (bigNum, 0));
    //dp1 is i - 1 dp
    //dp2 is current dp
    //should start at dp[i][10,000] because n(100) numbers with all contribution of -100, could be 10,000
    //however, when adding our contributions best case is adding 50 * 100, whcih is 5000 so it is fine

    //4 cases for our dp
    //new unfinished group with person i
    //adding to unfinished group with person i (not finishing group)
    //finishing unfinished group with person i
    //creating finished group with only person i
    dp1[0][1e4] = 1; 
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            for (ll p = 0; p < bigNum; p++){
                
                if (!dp1[j][p]) continue;
                //new unfinished group with person i ()
                if (j < n - 1) dp2[j + 1][p - a[i]] = (dp2[j + 1][p - a[i]] + dp1[j][p])%m;
                

                //adding to unfinished group, not finishing group
                dp2[j][p] = (dp2[j][p] + j * dp1[j][p])%m;

                //adding to unfinished group, finishing group
                if (j > 0) dp2[j - 1][p + a[i]] = (dp2[j - 1][p + a[i]] + j * dp1[j][p])%m;
                

                //creating finished group with only person i
                dp2[j][p] = (dp2[j][p] + dp1[j][p])%m;

            }
        }
        for (ll j = 0; j < n; j++){
            for (ll p = 0; p < bigNum; p++){
                dp1[j][p] = (dp2[j][p] % m);
                dp2[j][p] = 0;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= x; i++){
        ans = (ans + dp1[0][1e4 + i])%m;
    }
    cout << ans;

}