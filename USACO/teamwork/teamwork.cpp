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
    setIO("teamwork");
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector <int> dp(n + 1, 0);
    //okay, dp[i] represents best score from 0..i
    for (int i = 1; i <= n; i++){
        int curMax = a[i - 1];
        for (int j = 0; j < k; j++){
            if (i + j > n) break;
            curMax = max(curMax, a[i - 1 + j]);
            dp[i + j] = max(dp[i + j], dp[i - 1] + curMax * (j + 1));
        }
    }
    cout << dp[n];
}
