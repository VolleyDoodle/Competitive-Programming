#include <bits/stdc++.h>
using namespace std;
int n, m;
int curAns = 1, ans = 0;
void solve(){
    if (n % 2 && m % 2){
        ans +=curAns;
        curAns*=4;
        n = (n - 1)/2; m = (m - 1)/2;
        solve();
    }
}

int main(){
    cin >> n >> m;
    solve();
    cout << ans;
}