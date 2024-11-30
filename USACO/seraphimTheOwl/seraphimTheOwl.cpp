#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    vector <long long> a(n), b(n + 1), bpfs(n + 1);
    bpfs[n] = 0;
    b[n] = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        
    }
    for (int i = n - 1; i >= 0; i--){
        bpfs[i]+= (bpfs[i + 1] + b[i + 1]);
    }
    int curPos = n;
    for (int j = n - 1; j >= m; j--){
        if (b[j] > a[j]){ //go to j
            ans+= (bpfs[j] - (b[curPos] + bpfs[curPos])) + a[j];
            curPos = j;
        }
    }
    long long beforeAns = ans;
    for (int j = m - 1; j >= 0; j--){
        if (j == m - 1){
            ans+= (bpfs[j] - (b[curPos] + bpfs[curPos])) + a[j];
        }
        ans = min(ans, beforeAns + (bpfs[j] - (b[curPos] + bpfs[curPos])) + a[j]);
    }   
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}