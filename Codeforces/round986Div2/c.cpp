#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    ll n, m, v;
    cin >> n >> m >> v;
    vector <ll> a(n + 1);
    vector <ll> prefix(n + 1, 0), suffix(n + 2, 0), tot(n + 1, 0);
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll curAmt = 0;

    for (ll i = 1; i <= n; i++){
        curAmt+=a[i];
        prefix[i] = prefix[i - 1];
        if (curAmt >= v){
            prefix[i]++;
            curAmt = 0;
        }
        tot[i] = tot[i - 1] + a[i];
    }
    curAmt = 0;
    for (ll i = n; i >= 1; i--){
        curAmt+=a[i];
        suffix[i] = suffix[i + 1];
        if (curAmt >= v){
            suffix[i]++;
            curAmt = 0;
        }
    }
    //all prefix/suffix arrays indexed at 1
    bool pos = false;
    ll ans = 0;
    if (prefix[n] < m){
        cout << -1;
        return;
    }
    for (ll i = 0; i < n; i++){
        //start at i, end at whatever c
        ll idx = i + 1;
        ll need = m - prefix[idx - 1];
        //need to lower_bound(need) on suffix
        auto it = upper_bound(suffix.begin() + idx + 1, suffix.end(), need, greater <ll>());
        if (need <= 0 || it != suffix.begin()){
            //found ans;
            ll otheridx = it - suffix.begin() - 2;
            if (otheridx < idx) continue;
            ans = max(ans, tot[otheridx] - tot[idx - 1]);
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    ll t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}