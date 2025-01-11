#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        if (n < m){
            swap(n, m);
        }
        //n >= m now
        int ans = (n - 1) + 2;
        cout << ans << "\n";
    }
}