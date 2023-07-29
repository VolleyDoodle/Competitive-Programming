#include <bits/stdc++.h>
using namespace std;
int m = pow(10, 9) + 7;
int main(){
    int n, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++){
        ans = (2 * ans)%m;
    }
    cout << ans;
}