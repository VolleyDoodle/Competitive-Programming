#include <bits/stdc++.h>
#define ll long long
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
const int mod = 1e9 + 7;
//bit dp is quite the intersting concept tbh
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n), rgraph(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        rgraph[b - 1].push_back(a - 1);
    }
    //okay dp[S][i] -> subset && i
    vector <vector <int>> dp((1 << n), vector <int>(n, 0));
    dp[1][0] = 1;
    for (int s = 0; s < (1 << n); s++){
        //can only update from reversed
        //TE w/out following two lines
        //code doesnt TE with following one line
        if ((s & (1 << 0)) == 0) continue;
        //but need this line as overcounts 2^19 subsets w/ out it
		// also only consider subsets with the last city if it's the full subset
		if ((s & (1 << (n - 1))) && s != ((1 << n) - 1)) continue;
        for (int k = 0; k < n; k++){
            if (s & (1 << k)){
                //then take away this city and do the dp shii
                //but first gotta check if it can come from ts
                for (int bckNode : rgraph[k]){
                    //okay in the s
                    if (s & (1 << bckNode) && bckNode != k){
                        int val = s - (1 << k);
                        dp[s][k] += dp[val][bckNode];
                        dp[s][k] %= mod;
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1];

}