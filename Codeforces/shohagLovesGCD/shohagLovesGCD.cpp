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
    vector <int> S(m), a(n + 1, 0);
    for (int i = 0; i < m; i++)  cin >> S[i];
    sort(S.begin(), S.end());
    a[1] = S[m - 1];
    //bool pos = true;
    for (int i = 1; i <= n; i++){
        auto it = lower_bound(S.begin(), S.end(), a[i]);
        if (it == S.begin() && i <= n/2){
            cout << -1;
            return;
        }
        it--;
        
        int val = *it;
        for (int x = i + i; x <= n; x+=i){
            a[x] = val;
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";

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