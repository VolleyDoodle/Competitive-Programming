#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        long long n, ans = 1;
        cin >> n;
        while (n > 3){
            n/=4;
            ans*=2;
        }
        cout << ans << "\n";
    }
}