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
    ll x, m;
    int cnt = 0;
    cin >> x >> m;
    for (int i = 1; i <= x; i++){
        ll y = i ^ x;
        if (y > 0 && y <= m && y != x && (y%i == 0 || x%i == 0)){
            cnt++;
        }
    }
    cout << cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}