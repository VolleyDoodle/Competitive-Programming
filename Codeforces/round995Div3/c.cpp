#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> ans(m, 0), ms(m), ks(k);
    for (int i = 0; i < m; i++) cin >> ms[i];
    for (int i = 0; i < k; i++) cin >> ks[i];
    if (k < n - 1){
        //always impossible
        for (int& z : ans) cout << z;
        return;
    }
    if (k > n - 1){
        for (int& z : ans) cout << z + 1;
        return;
    }
    //else k = n - 1
    //how to find missing value?
    vector <bool> visited(n + 1, false);
    int unk;
    for (int i = 0; i < k; i++){
        visited[ks[i]] = true;
    }
    for (int i = 1; i < n + 1; i++){
        if (!visited[i]) unk = i;
    }
    for (int i = 0; i < m; i++){
        if (ms[i] == unk){
            cout << 1;
        } else{
            cout << 0;
        }
    }
    
    
}

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}