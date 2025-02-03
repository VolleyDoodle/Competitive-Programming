#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n, 0), pfs(n + 1, 0);
    for (ll i = 0; i < n; i++){
        ll tt; cin >> tt;
        a[i] = tt%m;
    }
    sort(a.begin(), a.end());
    for (ll i = 1; i <= n; i++){
        pfs[i] = pfs[i - 1] + a[i - 1];
    }
    ll totAns = LONG_LONG_MAX;
    ll mid = m/2;
    for (ll i = 0; i < n; i++){
        ll setTo = a[i], curAns = 0;
        //seting all other mods to setTo
        //split llo thirds basically
        if (a[i] <= mid){
            ll idx = upper_bound(a.begin(), a.end(), a[i] + mid) - a.begin();
            idx--;
            ll curAns = (i + 1) * (a[i]) - pfs[i + 1];
            curAns += pfs[idx + 1] - pfs[i + 1] - (a[i] * (idx - i));
            curAns+= ((m * (n - idx - 1)) - (pfs[n] - pfs[idx + 1])) + a[i] * (n - idx - 1);
            totAns = min(totAns, curAns);
        } else{
            //split llo thirds,
            //first subtract, then add, then subtract
            ll idx = lower_bound(a.begin(), a.end(), a[i] - mid) - a.begin();
            idx--;
            ll curAns = (m * (idx + 1)) + pfs[idx + 1] - a[i] * ((idx + 1));
            curAns += (a[i] * (i - idx)) - (pfs[i + 1] - pfs[idx + 1]);
            ll temp = pfs[n] - pfs[i + 1];
            ll temp2 = (a[i] * (n - i - 1));
            //curAns += (pfs[n] - pfs[i + 1]) - (a[i] * (n - i - 1));
            curAns += temp - temp2;
            totAns = min(totAns, curAns);
        }
        
    }
    cout << totAns;
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}