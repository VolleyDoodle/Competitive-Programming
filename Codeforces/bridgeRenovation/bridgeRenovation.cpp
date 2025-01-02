#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    if (n%3 == 0){
        ans += 2 * (n/3);
        
    } else if (n%3 == 1){
        ans += 2 * (n/3) + 1;

    } else if (n%3 == 2){
        ans += 2 * (n/3) + 2;
    }

    if (n%2 == 1){
        if (n%3 == 2){
            ans += n/2;
        } else{
            ans += n/2 + 1;
        }
    } else{
        ans += n/2;
    }
    cout << ans;
}