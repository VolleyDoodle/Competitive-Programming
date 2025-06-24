#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("movie");
    int n, l;
    cin >> n >> l;
    vector <vector <int>> start(n);
    vector <int> duration(n);
    for (int i = 0; i < n; i++){
        int c;
        cin >> duration[i] >> c;
        start[i].resize(c);
        for (int j = 0; j < c; j++){
            cin >> start[i][j];
        }
    }
    //lets just say dp[s] -> max possible duration using all s (so basically end time)
    vector <int> dp(1 << n, 0);
    int ans = INT_MAX;
    for (int s = 0; s < (1 << n); s++){
        for (int j = 0; j < n; j++){
            if (s & (1 << j)){
                auto it = upper_bound(start[j].begin(), start[j].end(), dp[s ^ (1 << j)]);
                if (it != start[j].begin()){
                    it--;
                    dp[s] = max(dp[s], *it + duration[j]);
                }
            }
        }
        if (dp[s] >= l){
            ans = min(ans, __builtin_popcount(s));
        }
    }
    if (ans == INT_MAX){
        cout << -1;
    } else{
        cout << ans;
    }

}