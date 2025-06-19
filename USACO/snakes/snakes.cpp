#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("snakes");
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <vector <int>> dp(k + 2, vector <int>(n + 1, 1e9));
    //dp[j][i] , i represents current group, j represents current switch/turns sued
    for (int i = 0; i <= k; i++){
        dp[i][0] = 0;
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        
        
        //loop w/ j represents turn
        for (int j = 1; j <= k + 1; j++){
            int curMax = a[i - 1];
            int runSum = 0;
            for (int x = 0; x < n; x++){
                if (i + x > n) break;
                curMax = max(curMax, a[i + x - 1]);
                runSum += a[i + x - 1];
                dp[j][i + x] = min(dp[j][i + x], dp[j - 1][i - 1] + (curMax * (x + 1) - runSum));
            }
        }
    }
    int fAns = 1e9;
    for (int i = 0; i <= k + 1; i++){
        fAns = min(dp[i][n], fAns);
    }
    cout << fAns;
}
