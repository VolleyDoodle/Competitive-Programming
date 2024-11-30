#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int l, n, rf, rb;
    cin >> l >> n >> rf >> rb;
    vector <pair <int, int>> restStops(n);
    vector <int> maxRestStops(n);
    for (int i = 0; i < n; i++){
        cin >> restStops[i].first >> restStops[i].second;
    }
    sort(restStops.begin(), restStops.end());
    int curMax = INT_MIN;
    for (int i = n - 1; i >= 0; i--){
        curMax = max(curMax, restStops[i].second);
        maxRestStops[i] = curMax;
    }
    long long ans = 0, bessieSec = 0, johnSec = 0;
    for (int i = 0; i < n; i++){
        if (i == 0){
            bessieSec+=restStops[i].first * rb;
            johnSec+=restStops[i].first * rf;
        } else{
            bessieSec+=(restStops[i].first - restStops[i - 1].first) * rb;
            johnSec+=(restStops[i].first - restStops[i - 1].first) * rf;
        }
        
        if (restStops[i].second == maxRestStops[i]){
            ans+=(johnSec - bessieSec) * maxRestStops[i];
            bessieSec = johnSec;
        }
    }
    cout << ans;


}