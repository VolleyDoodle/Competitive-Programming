#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll check(vector <ll>& a, vector <ll>& b){
    ll sum = 0;
    for (ll i = 0; i < a.size(); i++){
        sum += (a[i] == b[i]);
    }
    return sum;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    ll n, ans = 0;
    cin >> n;
    vector <ll> a(n), b(n), ca(n);
    for (ll i = 0; i < n; i++){
        cin >> a[i];
        ca[i] = a[i];
    }
    //n(n - 1)/2 somehtiing is not affectd
    for (ll i = 0; i < n; i++) cin >> b[i];
    int cnt = 0;
    for (ll i = 0; i < n; i++){
        for (ll j = i; j < n; j++){
            if (i != 0 && j != 0) cnt++;
            reverse(a.begin() + i, a.begin() + j + 1);
            ans += check(a, b);
            a = ca;
        }
    }
    //cout << cnt;
    cout << ans;
}