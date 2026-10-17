#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
const int mod = 1e9 + 7;
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int n, m;
    cin >> n >> m;
    vector <vector <int>> cnt(n, vector <int>(m + 2));

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (i == 0){
            if (x == 0){
                fill(cnt[0].begin() + 1, cnt[0].end() - 1, 1);
            }
            else{
                cnt[0][x] = 1;
            }
        } else{
            if (x == 0){
                for (int j = 1; j <= m; j++){
                    cnt[i][j] = (cnt[i][j] + cnt[i - 1][j - 1])%mod;
                    cnt[i][j] = (cnt[i][j] + cnt[i - 1][j])%mod;
                    cnt[i][j] = (cnt[i][j] + cnt[i - 1][j + 1])%mod;
                }
            } else{
                cnt[i][x] = (cnt[i][x] + cnt[i - 1][x - 1])%mod;
                cnt[i][x] = (cnt[i][x] + cnt[i - 1][x])%mod;
                cnt[i][x] = (cnt[i][x] + cnt[i - 1][x + 1])%mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++){
        ans = (ans + cnt[n - 1][i])%mod;
    }
    cout << ans;
}