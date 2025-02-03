#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n, k;
    cin >> n >> k;
    vector <long long> a(n), pfs(n + 1, 0);
    for (long long i = 0; i < n; i++){
        char c;
        cin >> c;
        a[i] = c - '0';
        (a[i] == 0 ? a[i] = -1 : a[i] = 1);
    }
    vector <pair <long long, long long>> order;
    for (long long i = n - 1; i >= 0; i--){
        pfs[i] = pfs[i + 1] + a[i];
        if (i == 0) continue;
        order.push_back({pfs[i], i});
    }
    sort(order.begin(), order.end(), greater<>());
    long long ans = 0, curScore = 0, idx = 0;
    for (auto element : order){
        curScore+=pfs[element.second];
        ans++;
        if (curScore >= k) break;
    }
    if (curScore >= k) cout << ans + 1;
    else cout << -1;
    
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    long long t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}