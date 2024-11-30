#include <bits/stdc++.h>
using namespace std;
int n, k;
bool check(long long maxSum, vector <int>& arr){
    long long curSum = 0, subArrayLeft = k;
    bool success = true;
    for (int i = 0; i < n; i++){
        curSum+=arr[i];
        if (curSum > maxSum){
            subArrayLeft--;
            if (subArrayLeft == 0){
                success = false;
                break;
            }
            curSum = arr[i];
            if (curSum > maxSum){
                success = false; break;
            }
        }
    }
    return success;

}
int main(){
    cin >> n >> k;
    vector <int> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    long long lo = 1, hi = sum, ans = sum;
    while (lo <= hi){
        long long mid = lo + (hi - lo)/2;
        if (check(mid, arr)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans;
}