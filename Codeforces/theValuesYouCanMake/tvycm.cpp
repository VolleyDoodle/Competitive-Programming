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
    int n, k;
    cin >> n >> k;
    vector <int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector <vector <bool>> dp(k + 1, vector <bool>(k + 1, false));
    dp[0][0] = true;
    for (int coin : c){
        for (int i = k; i >= coin; i--){
            for (int j = i; j >= 0; j--){
                dp[i][j] = (dp[i - coin][j] || dp[i][j]);
                if (j - coin < 0) continue;
                dp[i][j] = (dp[i - coin][j - coin] || dp[i][j]);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i <= k; i++){
        if (dp[k][i]) cnt++;
    }
    cout << cnt << "\n";
    for (int i = 0; i <= k; i++){
        if (dp[k][i]) cout << i << " ";
    }

}