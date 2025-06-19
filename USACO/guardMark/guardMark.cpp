#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
//but basically learned one thing
//trying factorial problem? (problem that need specific order) just use dp over subsets
//alreayd knew this but like? idk
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("guard");
    int n, h;
    cin >> n >> h;
    vector <vector <int>> a(n, vector <int>(3));
    //height, weight, strength
    for (int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    //dp[s][0] = cur safety factor, dp[s][1] = cur height
    vector <vector <int>> dp((1 << n), vector <int>(2, -1));
    dp[0][0] = INT_MAX;
    dp[0][1] = 0;
    int ans = -1;
    for (int s = 1; s < (1 << n); s++){
        for (int j = 0; j < n; j++){
            if (s & (1 << j)){
                dp[s][0] = max(dp[s][0], min(dp[s ^ (1 << j)][0] - a[j][1] , a[j][2]));
                dp[s][1] = max(dp[s][1], dp[s ^ (1 << j)][1] + a[j][0]);
            }
        }
        if (dp[s][1] >= h) ans = max(ans, dp[s][0]);
    }
    if (ans == -1){
        cout << "Mark is too tall";
    } else{
        cout << ans;
    }
}