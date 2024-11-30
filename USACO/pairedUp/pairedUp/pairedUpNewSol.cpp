#include <bits/stdc++.h>
using namespace std;
struct a{
    int amt, num;
};
int main(){
    //two pointers sol???
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n, ans = INT_MIN;
    cin >> n;
    vector <a> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i].amt >> nums[i].num;
    }
    sort(nums.begin(), nums.end(), [](a &x, a &y){return x.num < y.num;});
    int left = 0, right = n - 1;
    while (right >= left){
        int subtractAmt = min(nums[left].amt, nums[right].amt);
        ans = max(ans, nums[left].num + nums[right].num);
        nums[left].amt-=subtractAmt; nums[right].amt-=subtractAmt;
        if (nums[right].amt <= 0){
            right--;
        } if (nums[left].amt <= 0){
            left++;
        }
    }
    cout << ans;
}