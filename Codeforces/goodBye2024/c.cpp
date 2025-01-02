#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    //problem is symmetrical for sure
    //so basically just trying to see some sort of pattern
    //does not work will fix later
    int t;
    cin >> t;
    while (t--){
        int n, k, og;
        cin >> n >> k;
        og = n;
        long long ans = 0;
        //the result of n will be the length of the shortest array
       long long leastNum = LLONG_MAX;
        while (n/2 >= k){
            //basically means while we can divide by two
            if (n%2){
                //odd
                n/=2;
                leastNum = n;
            } else{
                n/=2;
            }
        }
        if (leastNum%2) leastNum = leastNum/2 + 1;
        else leastNum++;
        long long num = og/(leastNum);
        cout << (leastNum + num * leastNum) * num/2;
        cout << "\n";
    }
}