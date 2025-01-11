#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    //b e s s i e
    string s;
    vector <char> bessie = {'b', 'e', 's', 's', 'i', 'e'};
    cin >> s;
    vector <int> dp(7, 0);
    long long ans = 0;
    for (int i = 0; i < s.size(); i++){
        dp[0]++;
        if (s[i] == 'b'){
            dp[1]+=dp[0];
            dp[0] = 0;
        } else if (s[i] == 'e'){
            dp[2]+=dp[1];
            dp[1] = 0;
            if (dp[5] > 0){
                dp[6] += dp[5];
                dp[0]+=dp[5];
                dp[5] = 0;
                
            }
            
        } else if (s[i] == 's'){
            dp[4] += dp[3];
            dp[3] = 0;
            dp[3] += dp[2];
            dp[2] = 0;
        } else if (s[i] == 'i'){
            dp[5] += dp[4];
            dp[4] = 0;
        }
        ans+=dp[6];
    }
    cout << ans;
}