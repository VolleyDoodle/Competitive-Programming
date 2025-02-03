#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n, 0);
    for (ll i = 0; i < n; i++){
        ll tt; cin >> tt;
        a[i] = tt%m;
    }
    ll totAns = LONG_LONG_MAX;
    for (ll i = 0; i < n; i++){
        ll setTo = a[i], curAns = 0;
        //seting all other mods to setTo
        for (ll x = 0; x < n; x++){
            ll amt = abs(a[x] - setTo);
            amt%=m;
            curAns+= min(amt, m - amt);
        }   
        totAns = min(curAns, totAns);
    }
    cout << totAns;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}