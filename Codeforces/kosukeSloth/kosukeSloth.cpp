#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
const int mod = 1e9 + 7;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    ll n, k;
    cin >> n >> k;
    //keep on generating fibonacci numbers % k
    //until get {1, 1} cuz then at start
    if (k == 1){
        cout << n%mod << "\n";
        return;
    }
    ll a = 1, b = 1, index = 3; 
    ll sz;
    vector <ll> indices;
    while (true){
        int temp = a;
        a = b;
        b = b + temp;
        a%=k; b%=k;
        if (a == 0) indices.push_back(index - 1);
        if (a == 1 && b == 1){
            //pisano cycle found
            sz = index - 2;
            break;
        }
        index++;
    }
    //he wants the nth fib numer divisble by k
    //so (n/(indices).size()) * sz == index
    //then to that index add 
    ll ans = ((n / indices.size()) % mod) * (sz % mod) % mod;
    ans %= mod;
    if (n % indices.size() != 0){
        ans += (indices[(n % indices.size()) - 1]);
        ans%= mod;
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