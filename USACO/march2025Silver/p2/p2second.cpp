#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    ll n, a, b;
    cin >> n >> a >> b;
    //vector <pair <ll, ll>> nums(n);
    map <ll, ll> cows;
    for (ll i = 0; i < n; i++){
        ll ni, di;
        cin >> ni >> di;
        cows[di] = ni;
    }
    ll ans = 0;
    for (auto& p : cows){
        if (cows.count(a - p.first)){
            if (p.first == a - p.first){
                continue;
            }
            ll amt = min(cows[a - p.first], cows[p.first]);
            ans += amt;
            cows[a - p.first]-=amt;
            cows[p.first]-=amt;
        }
    }
    swap(a, b);
    for (auto& p : cows){
        if (cows.count(a - p.first)){
            if (p.first == a - p.first){
                continue;
            }
            ll amt = min(cows[a - p.first], cows[p.first]);
            ans += amt;
            cows[a - p.first]-=amt;
            cows[p.first]-=amt;
        }
    }
    for (auto& p : cows){
        if (cows.count(a - p.first)){
            if (p.first == a - p.first){
                ll amt = cows[p.first];
                amt = (amt / 2);
                ans += amt;
                amt*=2;
                cows[a - p.first]-=amt;
                continue;
            }
        }
    }
    swap(a, b);
    for (auto& p : cows){
        if (cows.count(a - p.first)){
            if (p.first == a - p.first){
                ll amt = cows[p.first];
                amt = (amt / 2);
                ans += amt;
                amt*=2;
                cows[a - p.first]-=amt;
                continue;
            }
        }
    }
    cout << ans;

}