#include <bits/stdc++.h>
using namespace std;
//brute force!!
int n;
long long ans = LLONG_MAX, group1 = 0, group2 = 0;
vector <int> nums;
void solve(int ct){
    //choose whether each element going to group1 or group2
    if (ct == n){
        ans = min(ans, abs(group1 - group2));
        return;
    }
    group1+=nums[ct];
    solve(ct + 1);
    group1-=nums[ct];
    group2+=nums[ct];
    solve(ct + 1);
    group2-=nums[ct];
    
}
int main(){

    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    solve(0);
    cout << ans;
}