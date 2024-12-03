#include <bits/stdc++.h>
using namespace std;
int ans = 0, n;
void brute(){
    int count = 0;
    for (int i = 1; i <= 14; i++){
        if (i%3 != 0 && i%5 != 0){
            count++;
        }
        if (count == n){
            ans+=i;
            break;
        }
    }
}
int main(){
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    cin >> n;
    if (n <= 8){
        brute();
    } else{
        ans += (n/8) * 15 - 1;
        n = n%8;
        brute();
        ans++;
    }
    cout << ans;
    
}