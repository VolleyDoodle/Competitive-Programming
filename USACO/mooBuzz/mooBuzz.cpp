#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    int n, threeCount = 0, fiveCount = 0, fifteenCount = 0;
    cin >> n;
    
    while (true){
        if (n/3 - threeCount == 0 && n/5 - fiveCount == 0){
            break;
        }
        /*if (n/3 - threeCount > 0 && n/5 - fiveCount == 0){
            n+=n/3 - threeCount;
            threeCount = n/3;
        }
        if (n/3 - threeCount == 0 && n/5 - fiveCount > 0){
            n+=n/5 - fiveCount;
            fiveCount = n/5;
        }*/

        
        n-=min(threeCount/5, fiveCount/3) - fifteenCount;
        n+=(n/3 - threeCount);  
        threeCount = n/3;    
        n+=(n/5 - fiveCount);
        fiveCount = n/5;
        fifteenCount = min(threeCount/5, fiveCount/3);
        
        
        
    }
    cout << n;
}