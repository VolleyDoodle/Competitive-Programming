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
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <int> a(n + 1);
        for (int i = 0; i < n; i++){
            cin >> a[i + 1];
        }
        vector <vector <int>> dp(2, vector <int>(n + 1, 2e5 + 10));
        //dp[i][j], i rep. turn, j rep. cur boss, dp[i][j] = cur amt notes of used to reach j
        //i == 0 -> friend, i == 1 -> you
        dp[0][0] = 0;
        for (int j = 0; j <= n; j++){
            for (int i = 0; i < 2; i++){
                if (i == 0){
                    if (j + 1 > n) continue;
                    dp[(i + 1)%2][j + 1] = min(dp[(i + 1)%2][j + 1], dp[i][j] + a[j + 1]);
                    if (j + 2 > n) continue;
                    dp[(i + 1)%2][j + 2] = min(dp[(i + 1)%2][j + 2], dp[i][j] + a[j + 1] + a[j + 2]);
                } else{
                    if (j + 1 > n) continue;
                    dp[(i + 1)%2][j + 1] = min(dp[(i + 1)%2][j + 1], dp[i][j]);
                    if (j + 2 > n) continue;
                    dp[(i + 1)%2][j + 2] = min(dp[(i + 1)%2][j + 2], dp[i][j]);
                }
            }
        }
        cout << min(dp[0][n], dp[1][n]) << "\n";
    }
}   