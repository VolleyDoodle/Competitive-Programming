#include <bits/stdc++.h>
using namespace std;
const int bigNum = 2 * pow(10, 5) + 1;
int main(){
    int n;
    int arr[bigNum];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long ans = 0;
    for (int i = 1; i < n; i++){
        ans+=max(0, arr[i - 1] - arr[i]);
        arr[i] = max(arr[i], arr[i-1]);
    }
    cout << ans;
}