#include <bits/stdc++.h>
using namespace std;
int log2(int a){
    int cnt = 0;
    while (a > 0){
        a/=2;
        cnt++;
    }
    return cnt - 1;
}

int gcd(int a, int b){
    if (b > a) swap(a, b);
    while (b > 0){
        a%=b;
        if (b > a) swap(a, b);
    }
    return a;
}
void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> a(n), d(n - 1), pfs(n + 1, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        pfs[i + 1] = pfs[i] + (a[i] == a[i - 1]);
    }
    for (int i = 0; i < n - 1; i++) d[i] = abs(a[i + 1] - a[i]);
    //now d[i] = |a[i + 1] - a[i]|, or abs difference
    //now use sparse table
    vector <vector <int>> dp(log2(n - 1) + 1);
    for (int j = 0; j <= log2(n - 1); j++){
        dp[j].resize(n - (1 << j));
        for (int i = 0; i < n - (1 << j); i++){
            if (j == 0) dp[j][i] = d[i];
            else{
                dp[j][i] = gcd(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        if (l == r || pfs[r] - pfs[l] == r - l){
            cout << 0 << " "; continue;
        }
        int length = log2(r - l);
        int ans = gcd(dp[length][l - 1], dp[length][r - 1 - (1 << length)]);
        cout << ans << " ";
    }
    
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}