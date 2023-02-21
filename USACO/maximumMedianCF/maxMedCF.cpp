#include <bits/stdc++.h>
using namespace std;
int n, k; vector <int> nums;
bool check (int x){
    long long sum = 0;
    for (int i = (n - 1)/2; i < n; i++){
        sum+=max(0, x - nums[i]);
    }
    return k >= sum;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    int ans = -1;
    nums.resize(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    //binary search x
    int r = 2 * pow(10, 9), l = 0, mid;
    while (l <= r){
        mid = l + (r - l)/2;
        if (check(mid)){
            ans = max(ans, mid);
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    cout << ans;
}