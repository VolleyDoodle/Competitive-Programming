#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll d = gcd(a, b);
    set <ll> nums;
    for (int i = 0; i < n; i++){
        int c; cin >> c;
        nums.insert(c%d);
    }
    //wiill always be optimal to add to min value of nums
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < nums.size(); i++){
        ans = min(ans, *(--nums.end()) - *nums.begin());
        ll t = *nums.begin();
        nums.erase(nums.begin());
        nums.insert(t + d);
    }
    cout << ans << "\n";
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}