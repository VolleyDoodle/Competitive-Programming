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
    int k;
    cin >> k;
    vector <int> a(k);
    vector <int> vis(k + 1, 0);
    for (int i = 0; i < k; i++){
        cin >> a[i];
        vis[a[i]]++;
    }
    for (int i = 1; i <= sqrt(k - 2); i++){
        if ((k - 2) % i == 0){
            if (vis[i] && vis[(k - 2)/i] && i != sqrt(k - 2)){
                cout << i << " " << (k - 2)/i;
                return;
            } if (i == sqrt(k - 2) && vis[i] >= 2){
                cout << i << " " << i;
                return;
            }
            
        }
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