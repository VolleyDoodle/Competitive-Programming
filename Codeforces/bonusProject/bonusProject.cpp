#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector <long long> a(n), b(n), ans(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    long long maxUnits = 0;
    for (int i = 0; i < n; i++){
        maxUnits+= a[i]/b[i];
        ans[i]+= a[i]/b[i];
    }
    if (maxUnits < k){
        for (int i = 0; i < n; i++) cout << "0 ";
        return 0;
    }
    for (int i = 0; i < n; i++){
        //can use maxUnits - k
        long long canUse = maxUnits - k;
        ans[i]-= min(a[i]/b[i], canUse);
        maxUnits -= min(a[i]/b[i], canUse);
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}