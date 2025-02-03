#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    //problem is symmetrical for sure
    //so basically just trying to see some sort of pattern
    //does not work will fix later
    //holy fucking shit this problem is fucking cancer i fucking hate this

    int t;
    cin >> t;
    while (t--){
        int n, k, og;
        cin >> n >> k;
        long long tN = n, curOdd = 1;
        long long ans = 0;
        bool notSet = true;
        while (tN >= k){
            if (tN%2 == 1){
                if (notSet){
                    //curOdd*= tN/2 + 1
                    curOdd = (tN/2 + 1 + (tN/2 + 1) + (curOdd - 1)*tN) * (curOdd)/2;
                    notSet = false;
                }
                else{
                    curOdd*=2;
                }
                ans += curOdd;
                tN/=2;
            } else{
                curOdd *=2;
                tN/=2;
            }
        }
        cout << ans << "\n";
    }
        
}