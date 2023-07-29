#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k, ans = INT_MAX;
    cin >> n >> k;
    vector <vector <int>> colors(k + 1, {0});
    vector <int> lastSeen(k + 1, 0);
    for (int i = 0; i < n; i++){
        int tempPlank;
        cin >> tempPlank;
        if (i - lastSeen[tempPlank] > 0){
            colors[tempPlank].push_back(i - lastSeen[tempPlank]);
        }
        lastSeen[tempPlank] = i + 1;
    }
    for (int i = 1; i <= k; i++){
        if (n - lastSeen[i] > 0){
            colors[i].push_back(n - lastSeen[i]);
        }
        sort(colors[i].begin(), colors[i].end(), [](int a, int b){return a > b;});
        colors[i][0]/=2;
        sort(colors[i].begin(), colors[i].end(), [](int a, int b){return a > b;});
        ans = min(ans, colors[i][0]);
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}