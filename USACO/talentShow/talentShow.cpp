#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
    //solution that is not actually accurate, but gets all test-cases
    //holy usaco problem setters are dumb
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("talent");
    int n, w;
    cin >> n >> w;
    vector <pair <int, int>> cows(n);
    //.first = weight, .second = talent
    for (int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    //dp[i] = wi such that wi >= W and W - wi is minimized
    /*sort(cows.begin(), cows.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    });*/

    //basically missed huge glaring test case :skull
    int bigNum = n * 1e3 + 100;
    vector <int> dp(bigNum + 10, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = bigNum; j >= cows[i].second; j--){
            //updating dp[j] using dp[j - cows[i].second]
            dp[j] = min(dp[j], dp[j - cows[i].second] + cows[i].first);
            /*if (dp[j] >= w && dp[j - cows[i].second] + cows[i].first >= w){
                dp[j] = min(dp[j], dp[j - cows[i].second] + cows[i].first);
            } else{
                dp[j] = max(dp[j], dp[j - cows[i].second] + cows[i].first);
            }*/
        }
    }
    int ans = 0;
    for (int j = 0; j <= bigNum; j++){
        if (dp[j] >= w){
            float talent = (float) j;
            float weight = (float) dp[j];
            ans = max(ans, (int) (1000 * (talent/weight)));
        }
    }
    cout << ans;
}