#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
bool tryAll(ll idx, vector <ll> a){
    for (ll i = idx + 1; i < a.size(); i++){
        vector <ll> v = a;
        rotate(v.begin() + idx, v.begin() + idx + 1, v.begin() + i + 1);
        ll mx1 = 0, mn1 = LLONG_MAX;
        bool thisPos = true;
        for (ll x = 0; x < a.size(); x++){
            if (v[x] < mx1 && v[x] > mn1){
                thisPos = false;
                break;
            }
            if (v[x] > mx1){
                mx1 = v[x];
            } if (v[x] < mn1){
                mn1 = v[x];
            }
        }
        if (thisPos) return true;
    }
    return false;
}
void solve(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }
     
    ll mx1 = 0, mx2 = 0 ,mn1 = LLONG_MAX, mn2 = LLONG_MAX;
    bool doProc = false, impos = false;
    ll endIdx = 0;
    for (ll i = 0; i < n; i++){
        if (a[i] < mx1 && a[i] > mn1){
            doProc = true;
            if (a[i] < mx2 && a[i] > mn2){
                impos = true;
            }
            endIdx = i;
            break;
        }
        if (a[i] >= mx1){
            mx2 = mx1;
            mx1 = a[i];
        } else if (a[i] > mx2){
            mx2 = a[i];
        } if (a[i] <= mn1){
            mn2 = mn1;
            mn1 = a[i];
        } else if (a[i] < mn2){
            mn2 = a[i];
        }
    }
    if (impos){
        cout << "NO";
        return;
    }
    if (!doProc){
        cout << "YES";
        return;
    }
    //do proceess
    //should be one element greater and one element 
    for (ll i = endIdx - 1; i >= 0; i--){
        //try element i and try all posible shift lefts/rotates
        //should take abt n^2
        bool pp = tryAll(i, a);
        if (pp){
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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