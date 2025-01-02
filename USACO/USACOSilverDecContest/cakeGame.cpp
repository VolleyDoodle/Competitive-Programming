#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector <long long> cakes(n);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        cin >> cakes[i];
        sum+=cakes[i];
    }
    /**int left = 0, right = cakes.size() - 1;
    long long elsie = 0;
    for (int i = 0; i < (n/2) - 1; i++){
        if (cakes[left] > cakes[right]){
            elsie+=cakes[left++];
        } else{
            elsie+=cakes[right--];
        }
    }
    long long bessie = 0;
    for (int i = left; i <= right; i++){
        bessie+=cakes[i];
    }*/
    vector <long long> pSum(n/2, 0), sSum(n/2, 0);
    for (int i = 0; i < (n/2) - 1; i++){
        pSum[i + 1] = pSum[i];
        pSum[i + 1]+=cakes[i];
    }
    int right = cakes.size() - 1;
    for (int i = (n/2) - 2; i >= 0; i--){
        sSum[i] = sSum[i + 1];
        sSum[i]+=cakes[right--];
    }
    long long elsie = -1;
    for (int i = 0; i < n/2; i++){
        elsie = max(elsie, pSum[i] + sSum[i]);
    }
    cout << sum - elsie << " " << elsie;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}