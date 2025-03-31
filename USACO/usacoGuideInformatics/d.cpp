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
    ll n, k, q;
    cin >> n >> k >> q;
    vector <ll> a(n + 2, 0);
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll failAmt = 0;
    for (ll i = 1; i <= n - 1; i++){
        if (a[i] - a[i + 1] >= 0){
            failAmt++;
            continue;
        }
    }
    a[n + 1] = 1e9;
    while (q--){
        ll i, x;
        cin >> i >> x;
        if (a[i] >= a[i + 1] && x < a[i + 1]){
            failAmt--;
        } if (a[i] <= a[i - 1] && x > a[i - 1]){
            failAmt--;
        }
        if (x >= a[i + 1] && a[i] < a[i + 1]) failAmt++;
        if (x <= a[i - 1] && a[i] > a[i - 1]) failAmt++;
        a[i] = x;
        if (failAmt == 0){
            ll tot = (a[n] - a[1] + 1) - n;
            if (tot >= k) cout << "YES";
            else cout << "NO";
        } else{
            cout << "NO";
        }
        cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    ll t;
    cin >> t;
    while (t--){
        solve();
        //cout << "\n";
    }
}