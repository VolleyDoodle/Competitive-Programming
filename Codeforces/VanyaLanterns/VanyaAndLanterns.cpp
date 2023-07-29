#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, l; 
    cin >> n >> l;
    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int ans = INT_MIN;
    for (int i = 0;i < n - 1; i++){
        //double tAns = 1.0 * (nums[i + 1] - nums[i])/2;
        ans = max(ans, (nums[i + 1] - nums[i]));
    }
    //cout << ans << "\n";
    ans = max(ans, 2 * nums[0]);
    ans = max(ans, 2 * (l - nums[n - 1]));
    cout << fixed << (double) ans/2;
}