#include <bits/stdc++.h>
#define ll long long
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> p(n), s(n);
    vector <int> prefix(n), suffix(n);
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    prefix[0] = p[0];
    for (int i = 0; i < n - 1; i++){
        prefix[i + 1] = max(prefix[i], p[i + 1]);
    }
    suffix[n - 1] = p[n - 1];
    for (int i = n - 1; i >= 1; i--){
        suffix[i - 1] = min(suffix[i], p[i - 1]);
    }
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        s[i] = (c == 'L' ? 0 : 1);
    }
    //L = 0, R = 1
    int cnt = 0;
    for (int i = 0; i < n - 1; i++){
        if (s[i] == 0 && s[i + 1] == 1 && prefix[i] > suffix[i + 1]){
            cnt++;
        }
    }
    while (q--){
        int index;
        cin >> index;
        index--;
        if (s[index] == 0 && s[index + 1] == 1 && prefix[index] > suffix[index + 1]){
            cnt--;
        }
        if (s[index] == 1 && s[index - 1] == 0 && prefix[index - 1] > suffix[index]){
            cnt--;
        }
        s[index]++;
        s[index]%=2;
        if (s[index] == 0 && s[index + 1] == 1 && prefix[index] > suffix[index + 1]){
            cnt++;
        }
        if (s[index] == 1 && s[index - 1] == 0 && prefix[index - 1] > suffix[index]){
            cnt++;
        }
        cout << (cnt > 0 ? "No" : "Yes") << "\n";

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
    }
}