#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string pre){
    freopen((pre + ".in").c_str(), "r", stdin);
    freopen((pre + ".out").c_str(), "w", stdout);
}

void solve(){
    ll n, c;
    cin >> n >> c;
    vector <ll> weights(n, 0);
    for (ll i = 0; i < n; i++){
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());
    //ll ans = 0;
    while (true){
        //keep on removing until no more. eventually if all arepossible it should stil lbreak
        auto it = upper_bound(weights.begin(), weights.end(), c);
        if (it == weights.begin()){
            break;
        } else{
            it--;
            ll value = *it;
            weights.erase(it);
            for (ll i = 0; i < weights.size(); i++){
                weights[i] = weights[i] * 2;
            }
        }
    }
   
    //cout << "reached";
    cout << weights.size() << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
}

