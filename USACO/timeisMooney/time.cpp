#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
//the thing about dp...
//is that
//its like weird
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("time");
    int n, m, c;
    cin >> n >> m >> c;
    vector <int> a(n + 1);
    vector <vector <int>> graph(n + 1);
    vector <vector <int>> dp(1001, vector <int>(n + 1, -1));
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }
    int ans = 0;
    dp[0][1] = 0;
    for (int t = 0; t < 1000; t++){
        for (int i = 1; i <= n; i++){
            if (dp[t][i] == -1) continue;
            for (int v : graph[i]){
                dp[t + 1][v] = max(dp[t + 1][v], dp[t][i] + a[v]);
            }
        }
        ans = max(ans, dp[t][1] - t * t * c);
    }
    cout << ans;

}
