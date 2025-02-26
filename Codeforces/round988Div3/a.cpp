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
    int n;
    cin >> n;
    vector <int> a(n), freq(n + 1, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        while (freq[i] >= 2){
            freq[i]-=2;
            ans++;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}