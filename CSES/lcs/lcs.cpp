#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
int longestCommonSubsequence(string text1, string text2) {
        vector <vector <int>> dp(text1.size() + 1, vector <int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++){
            for (int j = 1; j <= text2.size(); j++){
                if (text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j] + 1;
                } else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubsequence(s1, s2);
}