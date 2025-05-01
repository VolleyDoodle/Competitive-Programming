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
    setIO("feast");
    int t, a, b;
    cin >> t >> a >> b;

    vector <int> dp1(t + 1, 0);
    dp1[0] = 1;
    for (int i = 0; i <= t; i++){
        if (dp1[i] == 0) continue;
        if (i + a <= t){
            dp1[i + a] = dp1[i];
        } if (i + b <= t){
            dp1[i + b] = dp1[i];
        }
    }
    vector <int> dp2(t + 1, 0);
    for (int i = 0; i <= t; i++){
        if (dp1[i] == 0) continue;
        dp2[i/2] = 1;
    }
    for (int i = 0; i <= t; i++){
        if (dp2[i] == 0) continue;
        if (i + a <= t){
            dp2[i + a] = dp2[i];
        } if (i + b <= t){
            dp2[i + b] = dp2[i];
        }
    }
    int ans = 0;
    for (int i = 0; i <= t; i++){
        if (dp1[i]) ans = max(ans, i);
        if (dp2[i]) ans = max(ans, i);
    }
    cout << ans;
}