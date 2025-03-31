#include <bits/stdc++.h>
#define ll long long
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int idx = 0;
    char beg = s[0];
    while (idx < n && s[idx] == beg){
        idx++;
    }
    string ans = "";
    ans+=beg;
    int idx1 = n - 1;
    while (idx1 >= 0 && s[idx1] == s[n - 1]){
        idx1--;
    }
    if (idx > idx1){
        if (idx != n) ans += s[n - 1];
        cout << ans;
    }
    else{
        ans += s.substr(idx, (idx1 - idx) + 1);
        ans += s[n - 1];
        cout << ans;
    }
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