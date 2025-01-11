//push and pull dp
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    //earlier used recursion to solve this
    //now will use iteration
    //push dp, is updating future state with current state
    //pull dp is updating current state with past state
    //push dp sol below
    int n;
    cin >> n;
    vector <int> h(n), dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) cin >> h[i];

    /*for (int i = 0; i < n - 1; i++){
        //currently at pos i
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
        if (i + 2 < n){
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
            //what about case for dp[i + 1] to d[i + 2]?
            //will be handled in the next iteration
        }
    }*/
    
    //pull dp sol below
    for (int i = 1; i < n; i++){
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i - 1] - h[i]));
        if (i >= 2){
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i - 2] - h[i]));
        }
    }

    cout << dp[n - 1];


}