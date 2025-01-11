#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> h, dp;
//own solution
//uses recursion
int n;
int solve(int loc){
    //if (loc < 0) return 1e10;
    if (dp[loc] != -1){
        return dp[loc];
    }
    if (loc >= 2){
        dp[loc] =  min(solve(loc - 1) + abs(h[loc - 1] - h[loc]), solve(loc - 2) + abs(h[loc - 2] - h[loc]));
        return dp[loc];
    } else{
        //loc == 1;
        dp[loc] = solve(loc - 1) + abs(h[loc - 1] - h[loc]);
        return dp[loc];
    }

}
int main(){
    //dp woohoo
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    cin >> n;
    dp.resize(n, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        int hi;
        cin >> hi;
        h.push_back(hi);
    }
    ll ans = solve(n - 1);
    cout << ans;
}