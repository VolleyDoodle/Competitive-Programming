#include <bits/stdc++.h>

using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n;
    cin >> n;
    multiset <int> ms;
    for (int i = 0; i < n; i++){
        int tt; cin >> tt;
        ms.insert(tt);
    }
    int best = -1;
    auto it2 = ms.begin();
    while (it2 != prev(ms.end())){
        if (*next(it2) == *it2){
            best = *it2;
        }
        it2 = next(it2);
    }
    if (best == -1){
        cout << -1;
        return;
    }
    ms.erase(ms.find(best));
    ms.erase(ms.find(best));
    auto it = ms.begin();
    while (it != prev(ms.end())){
        if (*next(it) - *it < 2 * best){
            //found ans
            cout << best << " " << best << " " << *it << " " << *next(it);
            return;
        }
        it = next(it);
    }
    cout << -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}