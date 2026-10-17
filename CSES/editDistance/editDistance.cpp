#include <bits/stdc++.h>
#define ll long long

using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    string s1, s2;
    cin >> s1 >> s2;
    vector <vector <int>> dp(s1.size() + 1, vector <int>(s2.size() + 1, 0));
    for (int i = 0; i <= s1.size(); i++){
        dp[i][0] = i;
    }
    for (int i = 0; i <= s2.size(); i++){
        dp[0][i] = i;
    }


    //okayyy, for some reason this problem took some time to understand
    //think abt like this, we only modify s1 and are molding to become s2
    //dp[i][j] = value to modify s1[0: i - 1] to s2[0: j - 1]
    //given that dp[i - 1][j] already works with some value? then when we go to dp[i][j] we add another character to s1, but we can just delete that (+1)
    //given that dp[i][j - 1] already works with some value? then we go to dp[i][j], knowing we add another character to s2 (which again doesn't add by itself)
    //but now we have to add that character to s1
    //given dp[i - 1][j - 1] works, and s1[i - 1] == s2[j - 1] works, then no increase !
    //however if s1[i - 1] != s2[j - 1], then can still transition from dp[i - 1][j - 1] as a replacement operation (+ 1)
    for (int i = 1; i <= s1.size(); i++){
        for (int j = 1; j <= s2.size(); j++){
            dp[i][j] = dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]);
            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j], dp[i][j - 1] + 1));
        }
    }
    cout << dp[s1.size()][s2.size()];
}