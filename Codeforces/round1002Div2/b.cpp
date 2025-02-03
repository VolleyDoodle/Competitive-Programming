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
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == k){
        for (int i = 1; i < n; i+=2){
            if (a[i] != (i + 1)/2){
                cout << (i + 1)/2;
                return;
            }
        }
        cout << (k/2) + 1;
        return;
    }
    for (int i = 1; i < n - (k - 2); i++){
        if (a[i] != 1){
            cout << 1;
            return;
        }
    }
    cout << 2;
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