#include <bits/stdc++.h>
using namespace std;
int ownLowerBoundFn(vector <int> &nums, int x, int n){
    int l = 0, r = n - 1;
    int ans = INT_MAX;
    while (r >= l){
        int mid = l + (r - l)/2;
        //if (nums[mid] == x){
            //return nums[mid];
        if (nums[mid] >= x){
            ans = min(ans, nums[mid]);
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    return ans;
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << "Find lower_bound of what number? \n";
    int x;
    cin >> x;
    cout <<  ownLowerBoundFn(nums, x, n);

}