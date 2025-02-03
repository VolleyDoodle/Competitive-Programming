#include <bits/stdc++.h>
#include <math.h>
using namespace std;
const long long mod = 998244353;
long long ans = 1;
long long modPow(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod;  // Handle base greater than mod

    while (exponent > 0) {
        if (exponent % 2 == 1) {  // If exponent is odd, multiply base with result
            result = (result * base) % mod;
        }
        base = (base * base) % mod;  // Square the base
        exponent /= 2;  // Divide exponent by 2
    }

    return result;
}

// Function to calculate the modular inverse
long long modInverse(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}
void change (vector <int>& sV, vector <int>& v, int x, vector <int>& other){
    int curVal = v[x - 1];
    int idx = upper_bound(sV.begin(), sV.end(), curVal) - sV.begin() - 1;
    ans *= modInverse(min(sV[idx], other[idx]), mod)%mod;
    ans%=mod;
    v[x - 1]++;
    sV[idx]++;
    ans *= min(sV[idx], other[idx]);
    ans%=mod;

}
void solve(){
    ans = 1;
    int n, q;
    cin >> n >> q;
    vector <int> a(n), b(n), sa(n), sb(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sa[i] = a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        sb[i] = b[i];
    }
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    for (int i = 0; i < n; i++){
        ans *= min(sa[i], sb[i]);
        ans%=mod;
    }
    cout << ans%mod << "\n";
    for (int i = 0; i < q; i++){
        int o, x;
        cin >> o >> x;
        if (o == 1){
            change(sa, a, x, sb);
        } else{
            change(sb, b, x, sa);
        }
        cout << ans%mod << "\n";
    }
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}