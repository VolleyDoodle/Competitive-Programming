#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
const int bigNum = 1e5 + 1;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

bool win(int us, int opp){
    if (us == 1 && opp == 3) return true;
    if (us == 3 && opp == 2) return true;
    if (us == 2 && opp == 1) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("hps");
    int n, k;
    cin >> n >> k;
    //H == 1, P == 2, S == 3
    // 1 > 3, 3 > 2 , 2 > 1
    vector<vector<vector<int>>> dp(4, vector<vector<int>>(21, vector<int>(100001, 0)));
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        if (c == 'H') a[i] = 1;
        else if (c == 'P') a[i] = 2;
        else a[i] = 3;
    }
    for (int i = 0; i < n; i++){

        for (int j = 1; j < 4; j++){
            //j rep. cur symbol
            
            for (int x = 0; x <= k; x++){
                //x rep. cur turn
                dp[j][x][i + 1] = max(dp[j][x][i + 1], dp[j][x][i] + win(j, a[i]));
                if (x == k) continue;
                for (int t = 1; t < 4; t++){
                    if (t == j) continue;
                    //changing symbol to t
                    dp[t][x + 1][i + 1] = max(dp[t][x + 1][i + 1], dp[j][x][i] + win(t, a[i]));
                }
            }
        }
    }
    int ans = 0;
    for (int j = 1; j < 4; j++){
        for (int x = 0; x <= k; x++){
            ans = max(ans, dp[j][x][n]);
        }
    }
    cout << ans;

}