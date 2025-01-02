#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    b.push_back(0);
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans += max(0, a[i] - b[i + 1]);
    }
    cout << ans;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}