#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("subDiv.txt", "r", stdin);
    int n;
    cin >> n;
    vector <long long> pfs(n);
    unordered_map <int, int> m;
    m[0]++;
    long long ans = 0;
    for (int i = 0; i < n; i++){
        cin >> pfs[i];
        if (i > 0) pfs[i]+=pfs[i - 1];
        if (m.count((pfs[i]%n + n) % n)) ans+=m[(pfs[i]%n + n) % n];
        m[(pfs[i]%n + n) % n]++;
    }
    cout << ans;


}