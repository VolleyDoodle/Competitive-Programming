#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, ans = 0;
    cin >> n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    set<int> posNums;
    for (int i = 0; i < n; i++){
        posNums.insert(nums[i]);
        for (int x = i + 1; x < n; x++){
            posNums.insert(abs(nums[i] - nums[x]));
        }
    }
    for (int a : posNums){
        for (int b : posNums){
            for (int c : posNums){
                if (a >= b && b >= c){
                    vector <int> cur = {a, b, c, a + b, c + b, a + c, a + b + c};
                    bool works = true;
                    for (int num : nums){
                        if (find(cur.begin(), cur.end(), num) == cur.end()){
                            works = false;
                            break;
                        }
                    }
                    if (works){
                        ans++;
                    }
                }
                
            }
        }
    }
    cout << ans;
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