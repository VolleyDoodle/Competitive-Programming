#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;

    cin >> n >> k;
    vector <pair <int, int>> movies(n);

    for (int i = 0; i < n; i++){
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), []
        (const auto& a, const auto& b){
            return a.second < b.second;
        }
    );


    int ans = 0;
    multiset <int> endTimes;
    for (int i = 0; i < k; i++) endTimes.insert(0);
    for (int i = 0; i < n; i++){
        auto it = endTimes.upper_bound(movies[i].first);
        if (it == endTimes.begin()) continue;
        it--;
        ans++;
        endTimes.erase(it);
        endTimes.insert(movies[i].second);

    }

    cout << ans;
}