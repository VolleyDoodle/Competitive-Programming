#include <bits/stdc++.h>

using namespace std;

int main(){
    cout << "hi";
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, k, m;
    cin >> x >> y >> k >> m;
    if (x > y) swap(x, y);
    //y always greater than or equal to x
    int ans = min(abs(x - m), abs(y - m));
    ans = min(ans, m);
    if (k > 1){
        ans = min(ans, abs(m - (x + y)));
        int countK = 0, tempAns = 0;

        while (k > countK){
            tempAns+=x;
            ans = min(ans, abs(m - tempAns));
            countK+=2;
        }
        countK = 1, tempAns = y;
        while (k > countK){
            tempAns-=x;
            countK+=2;
            if (k > countK) ans = min(ans, abs(m - tempAns));
        }
    }
    cout << ans;

}