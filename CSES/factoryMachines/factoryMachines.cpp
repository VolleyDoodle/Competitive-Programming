#include <bits/stdc++.h>
using namespace std;
int n, t;
bool calc(long long& time, vector <int>& arr){
    long long curAmt = 0;
    for (int i = 0; i < n; i++){
        curAmt+=time/arr[i];
        if (curAmt >= t) break;
    }
    return curAmt >= t;
}
int main(){
    cin >> n >> t;
    vector <int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long lo = 1, hi = 1e18;
    long long ans = 1e18;
    while (lo <= hi){
        long long mid = lo + (hi  - lo)/2;
        if (calc(mid, arr)){
            ans = mid;
            hi = mid - 1;
        } else{
            lo = mid + 1;
        }
    }
    cout << ans;
}