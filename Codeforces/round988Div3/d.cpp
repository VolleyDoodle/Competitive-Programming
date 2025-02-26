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
    ll n, m, l;
    cin >> n >> m >> l;
    vector <pair <ll, ll>> hurdles(n + 1);
    vector <ll> locs(m), vals(m);
    hurdles[0] = {0, 0};
    for (ll i = 1; i <= n; i++){
        cin >> hurdles[i].f >> hurdles[i].s;
    }
    for (ll i = 0; i < m; i++){
        cin >> locs[i] >> vals[i];
    }
    ll cur = 1;
    ll ans = 0;
    priority_queue <ll, vector <ll>> pq;
    for (ll i = 1; i <= n; i++){
        pair <ll, ll> curH = hurdles[i];
        ll bef = hurdles[i - 1].s;
        ll start = upper_bound(locs.begin(), locs.end(), bef) - locs.begin();
        ll end = upper_bound(locs.begin(), locs.end(), curH.f) - locs.begin();
        for (ll i = start; i < end; i++){
            pq.push(vals[i]);
        }
        while (!pq.empty() && cur < (curH.s - curH.f) + 2){
            cur += pq.top();
            pq.pop();
            ans++;
        }
        if (pq.empty() && cur < (curH.s - curH.f) + 2){
            cout << -1;
            return;
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