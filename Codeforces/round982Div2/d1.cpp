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
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m), suffix(n + 1, 0);
    for (int i = 0; i <n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    b.push_back(0);
    for (int i = n - 1; i >= 0; i--){
        suffix[i] = max(suffix[i + 1], a[i]);
    }
    int k = 1, ans = 0;
    for (int i = 0; i < n; i++){
        
    }

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