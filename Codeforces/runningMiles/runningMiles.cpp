using namespace std;
#include <bits/stdc++.h>
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector <int> prefixMax(n), suffixMax(n);
    prefixMax[0] = a[0];
    for (int i = 1; i < n; i++){
        prefixMax[i] = max(prefixMax[i - 1], a[i] + i);
    }
    suffixMax[n - 1] = a[n - 1] - n + 1;
    for (int x = n - 2; x >= 0; x--){
        suffixMax[x] = max(suffixMax[x + 1],a[x] - x);
    }
    int ans = INT_MIN;
    for (int i = 1; i < n - 1; i++){
        ans = max(ans, a[i] + prefixMax[i - 1] + suffixMax[i + 1]);
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }

}