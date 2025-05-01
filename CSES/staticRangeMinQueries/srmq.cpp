#include <bits/stdc++.h>
using namespace std;
int log2(int num){
    int cnt = 0;
    while (num > 0){
        num/=2;
        cnt++;
    }
    return cnt - 1;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <vector <int>> dp(log2(n) + 1);
    for (int j = 0; j < log2(n) + 1; j++){
        dp[j].resize(n - (1 << j) + 1);
        for (int i = 0; i < n - (1 << j) + 1; i++){
            if (j == 0) dp[j][i] = a[i];
            else{
                dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    while (q--){
        int a, b;
        cin >> a >> b;
        int length = log2(b - a + 1);
        int ans = min(dp[length][a - 1], dp[length][b - (1 << length)]);
        cout << ans << "\n";
    }
}