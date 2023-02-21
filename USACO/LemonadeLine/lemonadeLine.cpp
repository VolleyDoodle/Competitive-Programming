using namespace std;
#include <bits/stdc++.h>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n; cin >> n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++){cin >> nums[i];}
    //sort(nums.begin(), nums.end(), greater <int>());
    sort(nums.begin(), nums.end(), [](const int &a, const int &b){return a > b;});
    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] >= cur){
            cur++; ans++;
        }
    }

    cout << ans;
}