#include <bits/stdc++.h>
#define ll long long
#define s second
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
    int n, c;
    cin >> n >> c;
    vector <int> a(n), dp(5e5 + 5, 0);
    int tot = 0, run = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        tot += (a[i] == c);
    }
    int ans = tot;
    //whole idea is...
    //dp[a[i]] represents best score from 0..i using a[i] as d val
    //both ends from l, r have to end with d b/c most optimal
    //
    for (int i = 0; i < n; i++){
        if (a[i] == c) run++;
        else{
            dp[a[i]] = max(run + 1, dp[a[i]] + 1);
            ans = max(ans, dp[a[i]] + tot - run);
        }
    }
    cout << ans;

}