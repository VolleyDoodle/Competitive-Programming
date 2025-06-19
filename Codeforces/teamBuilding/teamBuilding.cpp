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
    //setIO("txt");
    int n, P, k;
    //i fucking forgot there were k audience members
    cin >> n >> P >> k;
    vector <pair <int, int>> a(n);
    vector <vector <int>> p(n, vector <int>(P));
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < P; j++){
            cin >> p[i][j];
        }
    }
    //sort by audiences
    //and now
    //its basically optimal to use those as the audience
    //if we DON't end up using those, they HAVE to be in bit then
    //why should we sort thoo...
    //2d dp makes it easier to implement
    sort(a.begin(), a.end(), greater<>());
    vector <vector <ll>> dp(n + 1, vector <ll>(1 << P, 0));
    ll ans = 0;
    for (int i = 0; i < n; i++){
        //adding the "ith" person
        //okay for the ith person
        //either add them as a player
        //or add them as audience
        //OKAY THIS IS ADDING BTW

        //omfg, set represents player filled or not ?
        
        for (int s = 0; s < (1 << P); s++){
            //okay add them
            int curAmt = __popcount(s);
            dp[i + 1][s] = dp[i][s];
            //if player i is in the set, and this set is achievable by current i players
            if ((i + 1 >= curAmt)){
                //try player i in job j
                for (int j = 0; j < P; j++){
                    if (s & (1 << j)){
                        dp[i + 1][s] = max(dp[i + 1][s], dp[i][s ^ (1 << j)] + p[a[i].second][j]);
                    }
                    
                }
            }

            //but also try to leave it as audience
            if (i - curAmt < k && (i + 1 > curAmt)){
                dp[i + 1][s] = max(dp[i + 1][s], dp[i][s] + a[i].first);
            }
        }
        ans = max(ans, dp[i + 1][(1 << P) - 1]);
    }
    cout << ans;
}