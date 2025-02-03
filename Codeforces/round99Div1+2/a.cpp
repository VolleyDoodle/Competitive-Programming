#include <bits/stdc++.h>

using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

void solve(){
    int n;
    cin >> n;
    int eC = 0, oC = 0;
    for (int i = 0; i < n; i++){
        int tt;
        cin >> tt;
        if (tt%2 == 0) eC++;
        else oC++;
    }
    if (eC == 0){
        if (oC >= 2){
            cout << oC - 1;
            return;
        } else{
            cout << 0;
        }
    } else{
        cout << 1 + oC;
        return;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}