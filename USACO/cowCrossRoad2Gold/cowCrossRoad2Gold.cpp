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
    setIO("nocross");
    int n;
    cin >> n;
    vector <int> left(n), right(n);
    for (int i = 0; i < n; i++) cin >> left[i];
    for (int i = 0; i < n; i++) cin >> right[i];

    vector <vector <int>> dp(n + 1, vector <int>(n + 1, 0));
    //best case scenario where answer is n -> straight lines

    //dp[i][j] = most non-interesecting lines formed. using (left[0: i - 1] and right[0: j - 1])
    //want to maximize each occurence of dp[i][j] b/c of straight lines = most optimal thinking
    //now how do you update the dp?
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j - 1] + (abs(left[i - 1] - right[j - 1]) <= 4);
            dp[i][j] = max(dp[i - 1][j], max(dp[i][j], dp[i][j - 1]));
        }
        /*ans = max(ans, dp[i][n]);
        if (i == n){
            for (int j = 1; j <= n; j++){
                ans = max(ans, dp[n][j]);
            }
        }*/
    }
    cout << dp[n][n];
}