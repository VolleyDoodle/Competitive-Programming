#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> ans(n);
    for (int i = 0; i < n; i+=2){
        ans[i] = n - (i/2);
    }
    for (int i = 1; i < n; i+=2){
        ans[i] = (i + 1)/2;
    }
    for (int i = 0; i < n - 1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[n - 1];
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