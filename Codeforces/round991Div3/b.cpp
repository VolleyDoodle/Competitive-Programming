#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    long long eSum = 0, oSum = 0;
    int eAmt = 0, oAmt = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int t1;
        cin >> t1;
        if (i%2 == 0){
            eSum+=t1;
            eAmt++;
        } else{
            oSum+=t1;
            oAmt++;
        }
    }

    if (oSum%oAmt == 0 && eSum%eAmt == 0 && oSum/oAmt == eSum/eAmt){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    

    
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        //cout << "ans: ";
        solve();
        cout << "\n";
    }
}