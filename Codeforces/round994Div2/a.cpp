#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector <int> vals(n);
    for (int i = 0; i < n; i++){
        cin >> vals[i];
    }
    int left = 0, right = n - 1;
    while (vals[left] == 0){
        left++;
        if (left == n) break;
    }
    while (vals[right] == 0){
        right--;
        if (right < 0) break;
    }
    if (right == -1){
        cout << 0;
        return;
    }
    bool zeroFound = false;
    for (int i = left; i <= right; i++){
        if (vals[i] == 0){
            zeroFound = true;
        }
    }
    cout << (zeroFound ? 2 : 1);

}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}