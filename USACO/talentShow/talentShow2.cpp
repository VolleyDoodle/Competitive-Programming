#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
bool check(ll x, vector <pair <ll, ll>>& cows, ll w){
    ll n = cows.size();

    vector <ll> dp(w + 5, -1e9);
    //dp[i] for i < w, basically represents largest amt for specifically i
    //dp[w] largest amt for atleast w
    dp[0] = 0;
    for (ll i = 0; i < n; i++){
        ll cur_contr = 1000 * cows[i].second - cows[i].first * x;
        for (ll j = w; j >= 0; j--){
            ll k = min(w, j + cows[i].first);
            dp[k] = max(dp[k], dp[j] + cur_contr);
            //dp[j] = max(dp[j], dp[j - cows[i].first] + cows[i].second);
        }
    }
    return (dp[w] >= 0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("talent");
    ll n, w;
    cin >> n >> w;
    vector <pair <ll, ll>> cows(n);
    //.first = weight, .second = talent
    //basically uses this smart way to find a contribution for one cow
    //js check off edotiral
    for (ll i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    //1e6 * 250 + 10
    ll l = 0, r = 1e6 * 250 + 10;
    //mid already scaled by 1000
    while (l <= r){
        ll mid = l + (r - l)/2;
        if (check(mid, cows, w)){
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    cout << l - 1;
    
}