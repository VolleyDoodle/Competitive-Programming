#include <bits/stdc++.h>
using namespace std;
void solve(){
    int fk, lx, rx, ly, ry;
    long long k, ans = 0;
    cin >> fk >> lx >> rx >> ly >> ry;
    //let c = k^n
    //c can be atmost 31 values as 2^32 > 10^9
    //so this problem becoems y/x = c, or x * c = y
    //which in english is basically finding the multiples of c in y but y/c is in range of x
    k = 1;

    while (k <= ry){
        //in this loop
        //k = c, so x * c = y
        //split into two steps?
        //1. find least and greatest multiple c that fits in y
        //2. 
        long long maxY = (ry/k) * k;
        long long minY = (ly/k) * k;
        if (minY < ly) minY += k;
        long long maxX = rx * k;
        long long minX = lx * k;
        long long tAns = min(maxX, maxY) - max(minY, minX);
        if (tAns < 0){
            k*=fk;
            continue;
        }
        ans += tAns/k + 1;
        k*=fk;
    }
    cout << ans;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}