#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, ans = 0;
    cin >> n;
    int sum = 0;
    while(n--){
        int t;
        cin >> t;
        sum += t;
        int r = (int)sqrt(sum);
        if (r * r == sum && r%2){
            ans++;
        }
    }
    cout  << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}