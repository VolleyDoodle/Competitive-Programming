#include <bits/stdc++.h>
using namespace std;
//basically count number of factors of 5 and 2, but since we will always have more 2s than 5s we can just count 5s
int main(){
    long long n, ans = 0;
    cin >> n;
    //when we first divide by 5, will count on multiple of 5 on 25, then next when we mulitply will count other
    for (int i = 5; i <= n; i*=5){
        ans+= n/i;
    }
    cout << ans;
}