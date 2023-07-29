#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        long long y, x, ans = 1, edgeIndex = 0, add = 0;
        cin >> y >> x;
        if (x >= y){
            ans+= x/2;
            ans+=(((x - 1)/2) * (14 + 8 * (((x - 1)/2) - 1)))/2;
            if (x%2 == 1){
                ans-=(y - 1);
            } else{
                ans+=(y-1);
            }
        }
        else{
            ans+= (y - 1)/2;
            ans+= ((y/2) * (6 + 8 *((y/2) - 1)))/2;
            if (y%2 == 1){
                ans+=(x - 1);
            } else{
                ans-=(x - 1);
            }
        }
        cout << ans << "\n";
    }
}