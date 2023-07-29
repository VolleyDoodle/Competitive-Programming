#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, cur = 0, ans = 0, tAns = 0;
        cin >> n;
        for (int i = 0; i < n; i++){
            int temp; cin >> temp;
            if (temp == 0){
                tAns++;
            } else{
                ans = max(ans, tAns);
                tAns = 0;
            }
        }
        ans = max(ans, tAns);
        cout << ans << "\n";
        ans = 0, tAns = 0;
    }
}