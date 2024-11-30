#include <bits/stdc++.h>
using namespace std;
int lenOfBitRep(int num){
    int count = 0;
    while (num > 0){
        count++;
        num >>= 1;
    }
    return count;
}
void solve(){
    int n;
    cin >> n;
    vector <int> arr(n), editArr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (i == 0) editArr[i] = arr[i];
        else editArr[i] = max(editArr[i - 1], arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == editArr[i]) continue;
        ans = max(ans, lenOfBitRep(editArr[i] - arr[i]));
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