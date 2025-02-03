#include <bits/stdc++.h>

using namespace std;
#define ll long long
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    //somehwat stupid??
    //
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    map <ll, ll> bCnt, aCnt;
    set <int> as, bs;
    for (ll i = 0; i < n; i++){
        cin >> a[i];
        aCnt[a[i]]++;
        as.insert(a[i]);
    }
    for (ll i = 0; i < m; i++){
        cin >> b[i];
        bCnt[b[i]]++;
        bs.insert(b[i]);
    }
    while (true){
        int maxB = *bs.begin();
        if (as.empty() && bs.empty()){
            cout << "Yes";
            return;
        }
        if (as.empty() || bs.empty()){
            cout << "No";
            return;
        }
        if (*as.begin() > maxB){
            cout << "No";
            return;
        }
        if (as.count(maxB)){
            int mn = min(aCnt[maxB], bCnt[maxB]);
            aCnt[maxB]-= mn;
            bCnt[maxB]-= mn;
            if (aCnt[maxB] == 0){
                as.erase(maxB);
            }
            if (bCnt[maxB] == 0){
                bs.erase(maxB);
            }

        }
        else{
            int x = maxB/2, y = (maxB + 1)/2;
            bCnt[x] += bCnt[maxB];
            bCnt[y] += bCnt[maxB];
            bCnt[maxB] = 0;
            bs.erase(maxB);
            bs.insert(x);
            bs.insert(y);
        }
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