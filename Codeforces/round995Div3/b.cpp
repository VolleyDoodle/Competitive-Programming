#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    vector <int> nums(3);
    cin >> n >> nums[0] >> nums[1] >> nums[2];
    long long ans = 0;
    ans+= n/(nums[0] + nums[1] + nums[2]);
    ans*=3;
    int need = n%(nums[0] + nums[1] + nums[2]), cur = 0;
    while (cur < need){
        cur+=nums[ans%3];
        ans++;
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