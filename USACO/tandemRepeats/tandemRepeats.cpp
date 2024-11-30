#include <bits/stdc++.h>
using namespace std;
string s;
void slideWindow(int right){
   
}
void solve(){
    cin >> s;
    int n = s.size();
    int ans = 0;
    if (n == 1){
        cout << ans << '\n';
        return;
    }
    int count;
    for (int i = 1; i <= n/2; i++){
        count = 0;
        for (int j = 0; j < n - i; j++){
            if (s[j] == s[j + i] || s[j] == '?' || s[j + i] == '?'){//matching
                count++;
            } 
            else {
                count = 0;
            }
            if (count >= i){
                ans = 2 * i;
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}