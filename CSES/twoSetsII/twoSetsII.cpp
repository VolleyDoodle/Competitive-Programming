#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

const int m = 1e9 + 7;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");

    int n;
    cin >> n;

    int totSum = (n + 1) * n / 2;

    if (totSum % 2 == 1){
        cout << 0;
        return 0;
    }

    int x = totSum / 2;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int num = 1; num <= n; num++) {
        for (int i = x; i >= num; i--) {
            dp[i] = (dp[i] + dp[i - num]) % m;
        }
    }

    // Use modular inverse of 2
    int inv2 = (m + 1) / 2; // since 2^(m-2) mod m == (m+1)/2 when m=1e9+7
    cout << (1LL * dp[x] * inv2 % m);
}