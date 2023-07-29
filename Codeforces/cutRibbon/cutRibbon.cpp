#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    int arr[3];
    cin >> n >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    int a = arr[2], b = arr[1], c = arr[0];
    
    //n, a, b, c <= 4,000
    //basically just brute force m1 and m2
    int ans = INT_MIN;
    for (int i = 0; i <= n/c; i++){
        for (int x = 0; x <= n/b; x++){
            //i and x are equivalent to m2, m1
            int bruteAmount = i * c + x * b;
            if (n == bruteAmount){
                ans = max(ans, i + x);
                continue;
            }
            if ((n - bruteAmount) % a == 0 && n > bruteAmount){
                ans = max(ans,(n - bruteAmount)/a + i + x);
            }
        }
    }
    cout << ans;
}