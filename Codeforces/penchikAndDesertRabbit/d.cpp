#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n;
    cin >> n;
    vector <int> a(n), ans(n), suff(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ans[0] = a[0];
    for (int i = 1; i < n; i++){
        ans[i] = max(ans[i - 1], a[i]);
    }
    suff[n - 1] = a[n - 1];
    for (int i = n - 1; i >= 1; i--){
        suff[i - 1] = min(suff[i], a[i - 1]);
    }
    //ans[last element] should be the greatest value?
    for (int i = n - 2; i >= 0; i--){
        //compare i, and i + 1
        if (ans[i] > suff[i + 1]){
            //can switch
            ans[i] = max(ans[i], ans[i + 1]);
        }
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
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