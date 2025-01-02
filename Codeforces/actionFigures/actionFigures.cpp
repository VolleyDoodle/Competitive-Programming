#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> can(n + 1);
    set <int> buyVal;
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        can[i] = s[i - 1] - '0';
    }
    for (int i = n; i >= 1; i--){
        if (can[i]){
            buyVal.insert(i);
        } else{
            if (!buyVal.empty()){
                //remove largest
                auto it = buyVal.end();
                it--;
                ans+=i;
                buyVal.erase(it);
            } else{
                ans+=i;
            }
        }
    }
    int sz = buyVal.size();
    //in buy val can match first half
    while (buyVal.size() > sz/2){
        auto it = buyVal.begin();
        ans += *it;
        buyVal.erase(it);
        
    }
    cout << ans;
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