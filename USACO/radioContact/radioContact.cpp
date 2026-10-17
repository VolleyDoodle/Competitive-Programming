#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
int dist(pair <int, int>& p1, pair <int, int>& p2){
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("radio");

    int n, m;
    cin >> n >> m;

    vector <pair <int, int>> johnLocs(n + 1), bessieLocs(m + 1);

    cin >> johnLocs[0].first >> johnLocs[0].second;
    cin >> bessieLocs[0].first >> bessieLocs[0].second;

    string fs, bs;
    cin >> fs >> bs;

    map <char, pair <int, int>> dirs;
    dirs['N'] = {0, 1};
    dirs['S'] = {0, -1};
    dirs['E'] = {1, 0};
    dirs['W'] = {-1, 0};
    for (int i = 0; i < n; i++){
        johnLocs[i + 1] = {johnLocs[i].first + dirs[fs[i]].first, johnLocs[i].second + dirs[fs[i]].second};
    }
    for (int i = 0; i < m; i++){
        bessieLocs[i + 1] = {bessieLocs[i].first + dirs[bs[i]].first, bessieLocs[i].second + dirs[bs[i]].second};
    }
    //dp[i][j], ith direction FJ already taken, jth directio bessie already taken

    vector <vector <int>> dp(n + 1, vector <int>(m + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0] = (dp[i - 1][0] + dist(johnLocs[i], bessieLocs[0]));
    }
    for (int i = 1; i <= m; i++){
        dp[0][i] = (dp[0][i - 1] + dist(johnLocs[0], bessieLocs[i]));
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            //dp[i][j] = (dp[i - 1][j - 1] + dist(johnLocs[i], bessieLocs[j]));
            //dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist(johnLocs[i], bessieLocs[j]));
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            dp[i][j] += dist(johnLocs[i], bessieLocs[j]);
        }
    }
    cout << dp[n][m];
    
}