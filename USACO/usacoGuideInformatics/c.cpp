#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
int ans;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void doProc(int x, int y , int z){
    for (int i = 1e4; i >= 1; i--){
        ans = min(ans, abs(x - i) + min(y%i, i - y%i) + min(z%i, i - z%i));
    }
}
void solve(){
    int x, y, z;
    cin >> x >> y >> z;
    ans = INT_MAX;
    int bAns;
    doProc(x, y, z);
    bAns = ans;
    doProc(y, x, z);
    doProc(z, x, y);
    if (bAns == ans) cout << ans;
    else { cout << ans + 1;}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}