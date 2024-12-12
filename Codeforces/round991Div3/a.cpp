#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> lens(n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        lens[i] = s.size();
    }

    int ans = 0, curLen = 0;
    while (curLen <= m && ans < n){
        if (curLen + lens[ans] > m){
            break;
        }
        curLen += lens[ans];
        ans++;
        
    }
    cout << ans;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        //cout << "ans: ";
        solve();
        cout << "\n";
    }
}