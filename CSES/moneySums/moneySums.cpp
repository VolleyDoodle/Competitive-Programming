#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
const int bigNum = 1e5;
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int n;
    cin >> n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector <int> dp(bigNum + 1, 0);
    dp[0] = 1;
    for (int num : nums){
        for (int i = bigNum; i >= 0; i--){
            if (i - num < 0) break;
            dp[i] = max(dp[i], dp[i - num]);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= bigNum; i++){
        if (dp[i] != 0) cnt++;
    }
    cout << cnt << "\n";
    for (int i = 1; i <= bigNum; i++){
        if (dp[i] != 0) cout << i << " ";
    }
}