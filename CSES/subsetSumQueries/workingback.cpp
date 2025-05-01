#include <bits/stdc++.h>

using namespace std;
const int m = 998244353;
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);


    vector <int> cnt(5001, 0);
    
    //lets see, 5,10,1,3,1,7,4 sum to 10
    //two 1s, and 5, 1, 4 is counted twice
    
    vector <int> nums = {1, 1, 1, 2, 4, 5};
    int k = 6;
    vector <int> dp(k + 1, 0);
    dp[0] = 1;
    for (int num : nums){
        for (int i = k; i >= 0; i--){
            if (i - num < 0) continue;
            dp[i] += dp[i - num];
        }
    }

    cout << dp[k]%m << "\n";
    fill(dp.begin(), dp.end(), 0);
}
