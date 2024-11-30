#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector <long long> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector <long long> diffArray(n + 1);
    vector <long long> multiFactor(n);
    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        diffArray[x - 1]++; diffArray[y]--;
    }
    long long amt = 0;
    for (int i = 0; i < n; i++){
        amt+=diffArray[i];
        multiFactor[i] = amt;
    }
    sort(multiFactor.begin(), multiFactor.end());
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans+=arr[i] * multiFactor[i];
    }
    cout << ans;
    
}