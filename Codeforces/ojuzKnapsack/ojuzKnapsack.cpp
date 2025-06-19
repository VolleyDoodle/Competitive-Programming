#include <bits/stdc++.h>
#define ll long long
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
    int s, n;
    cin >> s >> n;

    vector <vector <pair <int, int>>> sort_weights(2001);
    for (int i = 0; i < n; i++){
        int v, w, k;
        cin >> v >> w >> k;
        sort_weights[w].push_back({v, k});
    }
    vector <int> dp(s + 1, 0);
    for (int i = 1; i <= s; i++){
        sort(sort_weights[i].begin(), sort_weights[i].end(), greater <>());
        int curAmt = 0;
        int curIndex = 0;
        while (curIndex < sort_weights[i].size() && curAmt <= s/i){
            //do the dp *****
            int addTo = 0;
            for (int j = 0; j < min(s/i - curAmt, sort_weights[i][curIndex].second); j++){
                for (int k = s; k >= i; k--){
                    dp[k] = max(dp[k], dp[k - i] + sort_weights[i][curIndex].first);
                }
                addTo = j;
            }
            curAmt+= (addTo + 1);
            curIndex++;
        }
    }
    cout << dp[s];
}