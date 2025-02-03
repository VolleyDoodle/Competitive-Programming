#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
    //make a always larger
    while (b != 0){
        a%=b;
        swap(a, b);
    }
    return a;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--){
        ll l, r, g;
        cin >> l >> r >> g;
        ll a = (l/g) * g;
        if (a < l) a += g;
        ll b = (r/g) * g;
        //ll tb = b;
        bool ans = false;
        for (ll i = b - a; i >= 0; i -= g){
            for (ll x = a; x + i <= r; x+=g){
                if (gcd(x, x + i) == g){
                    ans = true;
                    cout << x << " " << x + i;
                    break;
                    //good
                }
            }
            if (ans) break;
        }
        if (!ans) cout << "-1 -1";
        cout << "\n";
        
    }
}