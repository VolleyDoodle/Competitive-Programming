#include <bits/stdc++.h>
#define ll unsigned long long
#define s second
#define f first
const ll m = 1e9 + 7;
using namespace std;
ll div2(ll num){
    ll count = 0;
    while (num%2 == 0){
        num/=2;
        count++;
    }
    return count;
}
ll calc(ll twoCount){
    ll base = 2;
    ll res = 1;
    while (twoCount > 0){
        if (twoCount%2){
            res = ((res % m) * (base % m)) % m;
        }
        base = (base * base) % m;
        twoCount/=2;
    }
    return res%m;
}
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    ll n;
    cin >> n;
    vector <ll> a(n), ans(n);
    //i dont get get ts
    stack <pair <ll, ll>> stk;
    ll curAns = 0;
    for (ll i = 0; i < n; i++){
        cin >> a[i];

        ll pow = div2(a[i]);
        ll odd = a[i] / (1ULL << pow);
        while (!stk.empty()){
            if (pow >= 30 || stk.top().f <= odd * calc(pow)){
                auto cur = stk.top();
                stk.pop();
                pow += cur.s;
                curAns = (curAns + m - (cur.f * calc(cur.s)) % m) % m;
                curAns = (curAns + cur.f) % m;
            } else{
                break;
            }
        }
        if (pow != 0) stk.push({odd, pow});
        curAns = (curAns + (odd % m * calc(pow)%m)) % m;
        cout << curAns << " ";
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    ll t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}