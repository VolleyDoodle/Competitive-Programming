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
    if (n <= 4) cout << -1;
    else{
        for (int i = 1; i <= n; i+=2){
            if (i!=5) cout << i << " ";
        }
        cout << 5 << " 4 ";
        for (int i = 2; i <= n; i+=2){
            if (i!=4) cout << i << " ";
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