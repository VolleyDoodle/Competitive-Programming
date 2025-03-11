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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll cnt = 0;
    //if (a == c && b == d) cout << 0;
    while (c >= a && d >= b){
        if (c >= d){
            ll steps = c / d;
            c -= steps * d;
            cnt+=steps;
            if (b == d && a >= c && (a - c)%b == 0){
                cnt-= (a - c)/b;
                cout << cnt;
                return;
            }
        } else if (d > c){
            ll steps = d / c;
            d -= steps * c;
            cnt+=steps;
            if (a == c && b >= d && (b - d)%a == 0 ){
                cnt -= (b - d)/a;
                cout << cnt;
                return;
            } 
        }
        
    }
    cout << -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    ll t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}