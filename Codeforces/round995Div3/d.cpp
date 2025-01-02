#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n, x, y;
    cin >> n >> x >> y;
    vector <long long> nums(n);
    long long tot = 0, lower, upper;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        tot+=nums[i];
    }
    lower = tot - y;
    upper = tot - x;
    //inclusive btw
    sort(nums.begin(), nums.end());
    long long ans = 0;
    for (int i = 0; i < n; i++){
        auto it1 = lower_bound(nums.begin(), nums.end(), lower - nums[i]);
        //it1 points to place that in the array,
        //that element and others are equal to or greater than lower - nums[i]
        auto it2 = upper_bound(nums.begin(), nums.end(), upper - nums[i]);
        it2--;
        ans+=max(0, int(it2 - it1) + 1);
        if (i >= it1 - nums.begin() && i <= it2 - nums.begin()) ans--;
    }
    cout << ans/2;

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