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
    int n, x;
    cin >> n >> x;
    vector <int> price(n), pages(n);
    for (int i = 0; i < n; i++){
        cin >> price[i];
    }
    for (int i = 0; i < n; i++){
        cin >> pages[i];
    }
    vector <int> dp(x + 1, 0);
    for (int j = 0; j < n; j++){
        int p = price[j];
        for (int i = x; i >= 0; i--){
            if (i - p < 0) break;
            dp[i] = max(dp[i], dp[i - p] + pages[j]);
        }
    }
    cout << dp[x];
}