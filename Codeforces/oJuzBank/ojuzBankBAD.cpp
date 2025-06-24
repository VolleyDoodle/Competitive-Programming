#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
//this was really stupid?
//thought iwas huge ahhgenius
//turns out im just dumbahhh
//ill leave this as a sign of my short sightedness :(
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    vector <int> coins(m);
    vector <bool> dp(sum + 1, false);
    for (int i = 0; i < m; i++){
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int c : coins){
        for (int i = sum; i >= c; i--){
            dp[i] = (dp[i - c] || dp[i]);
        }
    }
    int curSum = 0;
    bool pos = true;
    for (int i = 0; i < n; i++){
        curSum += a[i];
        if (!dp[curSum]) pos = false;
    }
    cout << (pos ? "YES" : "NO");
}