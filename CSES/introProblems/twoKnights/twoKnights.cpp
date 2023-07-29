#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    for (long long k = 1; k <= n; k++){
        long long ans = (k * k) * ((k * k) - 1);
        ans/=2;
        ans-= 4 * (k - 2) * (k - 1);
        cout << ans << "\n";
    }
}