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
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector <vector <int>> dp(h + 1, vector <int>(w + 1, 0));
    for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) dp[i][j] = i * j;
    vector <pair <int, int>> plates(n);
    for (int i = 0; i < n; i++){
        cin >> plates[i].f >> plates[i].s;
        dp[plates[i].s][plates[i].f] = 0;
    } 
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            for (int x = 1; x <= j; x++){
                dp[i][j] = min(dp[i][j], dp[i][x] + dp[i][j - x]);
            }   
            for (int y = 1; y <= i; y++){
                dp[i][j] = min(dp[i][j], dp[y][j] + dp[i - y][j]);
            }
        }
    }
    cout << dp[h][w];


}