#include <bits/stdc++.h>
using namespace std;
long long n, k, m, X;

bool f(){
    long long g = 0, day = 0;
    long long a = n - g, cur = a/X;
    while(cur > m && day <= k){
        long long cDay = (a - cur * X)/cur; cDay++;
        day +=cDay ;
        g+=cDay* cur;
        a = n - g;
        cur = a/X;
    }
    if (g + (k - day) * m >= n){
        return true;
    } else{
        return false;
    }
}
int main(){ 
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);

    cin >> n >> k >> m;
    //binary search X
    long long left = 1, right = n/2, ans;
    while (left <= right){
        X = left + (right - left)/2;
        if (f()){
            ans = X;
            left = X + 1;
        } else{
            right = X - 1;
        }
    }
    cout << ans;

}