#include <bits/stdc++.h>

using namespace std;
const long long m = 998244353;
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    long long q, k;
    cin >> q >> k;
    multiset<long long> nums;
    vector <long long> cnt(5001, 0);
    vector <long long> dp(k + 1, 0);
    dp[0] = 1;
    while (q--){
        char op;
        long long num;
        cin >> op >> num;
        
        if (op == '+'){
            for (long long i = k; i >= 0; i--){
                if (i - num < 0) break;
                dp[i] = (dp[i]%m  + dp[i - num]%m)%m;
            }
        } else{
            for (long long i = 0; i <= k; i++){
                if (i + num > k) break;
                dp[i + num]-= dp[i];
                dp[i + num] += m;
                dp[i + num]%=m;
            }
        }
        cout << dp[k]%m << "\n";
        
    }
}