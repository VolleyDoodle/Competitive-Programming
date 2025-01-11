#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    map <int, int> times;
    for (int i = 0; i < n; i++){
        int tt;
        cin >> tt;
        times[tt]++;
    }
    priority_queue<pair <int, int>, vector <pair <int, int>>, greater <pair<int,int>>> pq;
    for (auto& e : times){
        pq.push({e.second, e.first});
    }
    while (pq.top().first <= k){
        auto cur = pq.top();
        pq.pop();
        k-=cur.first;
    }
    int ans = pq.size();
    cout << max(1, ans);
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