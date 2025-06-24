#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
//order problem
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int n, x;
    cin >> n >> x;
    //lets say dp[s][0], represents set s and current elevators needed
    //dp[s][1] will represent current amount of space USED
    
    //rly simple idea woohoo
    vector <int> weights(n);
    for (int i = 0; i < n; i++){
        cin >> weights[i];
    }   
    vector <vector <int>> dp(1 << n, vector <int>(2, 21));
    dp[0] = {0, 0};
    for (int s = 1; s < (1 << n); s++){
        for (int j = 0; j < n; j++){
            if (s & (1 << j)){
                int add = 0;
                //either need a new elevator
                if (weights[j] + dp[s ^ (1 << j)][1] > x){
                    if (dp[s][0] > dp[s ^ (1 << j)][0] + 1){
                        dp[s] = {dp[s ^ (1 << j)][0] + 1, weights[j]};
                    } if (dp[s][0] == (dp[s ^ (1 << j)][0] + 1) && dp[s][1] > dp[s ^ (1 << j)][1]){
                        dp[s] = {dp[s ^ (1 << j)][0] + 1, weights[j]};
                    }
                }
                else{ //or can keep on this one
                    if (dp[s][0] > dp[s ^ (1 << j)][0]){
                        dp[s] = {dp[s ^ (1 << j)][0], dp[s ^ (1 << j)][1] + weights[j]};
                    } if (dp[s][0] == dp[s ^ (1 << j)][0] && dp[s][1] > dp[s ^ (1 << j)][1] + weights[j]){
                        dp[s] = {dp[s ^ (1 << j)][0], dp[s ^ (1 << j)][1] + weights[j]};
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][0] + 1;
}