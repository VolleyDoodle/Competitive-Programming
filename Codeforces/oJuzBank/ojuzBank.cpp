
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
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector <int> coins(m);
    for (int i = 0; i < m; i++){
        cin >> coins[i];
    }
    //dp[s] ->  represents current salary paying + overflow
    //s represents subset 
    //this is an ordering problem, because given some salaries we need to pay
    //if it is possible, some order exists of the bank notes where we can just pay the salaries
    //if no order exists, then it is impossible
    //vector <vector <bool>> dp(n, vector <bool>(1 << m, false));
    vector <pair <int, int>> dp(1 << m, {-1, -1});
    //i believe that this loop for n isnt it actually needed
    //instead you can kinda build the answer as you go through subsets

    dp[0] = {0, 0};
    for (int s = 1; s < (1 << m); s++){
        for (int j = 0; j < m; j++){
            if (s & (1 << j)){
                //okay, we are adding coin j to s / {j}
                //dp[s / {j}] should have index of current salary paying, and what is amt currently payed
                //make sure not transitions from bad states
                if (dp[s ^ (1 << j)].first == -1) continue;

                if (dp[s ^ (1 << j)].second + coins[j] == a[dp[s ^ (1 << j)].first]){
                    dp[s] = max(dp[s], make_pair(dp[s ^ (1 << j)].first + 1, 0));
                } else if (dp[s ^ (1 << j)].second + coins[j] < a[dp[s ^ (1 << j)].first]){
                    dp[s] = max(dp[s], make_pair(dp[s ^ (1 << j)].first, dp[s ^ (1 << j)].second + coins[j]));
                }
            }
        }
    }
    /*for (int i = 0; i < n; i++){
        for (int s = 1; s < (1 << m); s++){
            for (int j = 0; j < m; j++){
                if (s & (1 << j)){
                    //okay, we are adding coin j to s / {j}
                    //dp[s / {j}] should have current count of salaries paid, and what is "overflow"
                    //make sure not transitions from bad states
                    if (dp[s ^ (1 << j)].first < i) continue;

                    if (dp[s ^ (1 << j)].first == i + 1){
                        dp[s] = max(dp[s], make_pair(dp[s ^ (1 << j)].first, dp[s ^ (1 << j)].second + coins[j]));
                    }

                    else if (dp[s ^ (1 << j)].second + coins[j] == a[i]){
                        dp[s] = max(dp[s], make_pair(dp[s ^ (1 << j)].first + 1, 0));
                    } else if (dp[s ^ (1 << j)].second + coins[j] < a[i]){
                        dp[s] = max(dp[s], make_pair(dp[s ^ (1 << j)].first, dp[s ^ (1 << j)].second + coins[j]));
                    } //otherwise, adding this coins goes above salary, so pretty useless
                }
            }
        }
    }*/
    bool pos = false;
    for (int s = 0; s < (1 << m); s++){
        if (dp[s].first == n){
            pos = true;
        }
    }
    cout << (pos ? "YES" : "NO");
}
