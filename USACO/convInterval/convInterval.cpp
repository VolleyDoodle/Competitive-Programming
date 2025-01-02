#include <bits/stdc++.h>
using namespace std;

int main(){
    //main logic is that
    //for two intervals, the logic will hold, just need to find which ks
    //allooottt  of prefix sums
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector <long long>  as(m + 1), bs(m + 1);
    vector <long long> ks(2*m + 2);
    for (long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        as[a]++;
        bs[b]++;
    }
    for (long long i = 0; i <= m; i++){
        for (long long x = 0; x <= m; x++){
            ks[i + x]+= as[i] * as[x];
            ks[i + x + 1] -= bs[i] * bs[x];
        }
    }
    long long ans = 0;
    for (long long i = 0; i <= 2 * m; i++){
        ans+=ks[i];
        cout << ans << "\n";
    }

}