#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> elsie(n);
    set <int> bessie;
    vector <bool> visited(2 * n + 1);
    for (int i = 0; i < n; i++){
        int t1;
        cin >> t1;
        visited[t1] = true;
        elsie[i] = t1;
    }
    for (int i = 1; i <= 2 * n; i++){
        if (!visited[i]) bessie.insert(i);
    }
    int ans = 0;
    auto mid = next(bessie.begin(), n/2);
    set <int> lowerHalf(bessie.begin(), mid), upperHalf(mid, bessie.end());
    for (int i = 0; i < n/2; i++){
        auto it = upperHalf.lower_bound(elsie[i]);
        if (it == upperHalf.end()) continue;
        upperHalf.erase(it);
        ans++;
    }
    for (int i = n/2; i < n; i++){
        auto it = lowerHalf.lower_bound(elsie[i]);
        if (it == lowerHalf.begin()) continue;
        it--;
        lowerHalf.erase(it);
        ans++;
    }
    cout << ans;

}