#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; 
    cin >> n >> q;
    vector <int> nums(n);
    nums.push_back(0);
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    while (q--){
        int l, r; cin >> l >> r;
        auto low = lower_bound(nums.begin(),  nums.end(), l);
        auto high = upper_bound(nums.begin(), nums.end(), r); 
        int lowIndex = low - nums.begin(), highIndex = high - nums.begin();
        cout << high - low << "\n";
    }

    
}