#include <bits/stdc++.h>
using namespace std;
//cannot use avg for this problem b/c of
//test cases like
//3 4 4 4 4 4 4
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, median;
    
    cin >> n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long ans = 0;
    median = nums[n/2];
    for (int i = 0; i < n; i++){
        ans+= abs(median - nums[i]);
    }
    cout << ans;


}