#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 0;
vector <int> fib, fibFunc;
void solve(){
    if (fibFunc.size() == k){
        ans++;
        return;
    }
    fibFunc.push_back(fibFunc[fibFunc.size() - 2] - fibFunc[fibFunc.size() - 1]);
    if (fibFunc[fibFunc.size() - 1] <= fibFunc[fibFunc.size() - 2]){
        solve();
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        fib.push_back(n);
        fib.push_back(n); fib.push_back(0);
        for (int i = 1; i <= n/2 + 1; i++){
            fibFunc = fib;
            solve();
            fib[1]--; fib[2]++;
        }
        cout << ans << "\n";
        ans = 0;
        fib.clear();
    }
    
}