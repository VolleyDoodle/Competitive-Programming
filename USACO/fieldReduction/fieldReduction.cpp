#include <bits/stdc++.h>
using namespace std;
set <pair <int, int>> outliers;
int main(){
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin >> n;
    vector <pair <int, int>> xy(n), yx;
    for (int i = 0; i < n; i++){
        cin >> xy[i].first >> xy[i].second;
    }
    yx = xy;
    sort(xy.begin(), xy.end());
    sort(yx.begin(), yx.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });
    for (int i = 0; i < 3; i++){
        outliers.insert(xy[i]);
        outliers.insert(yx[i]);
    }
    for (int i = n - 3; i < n; i++){
        outliers.insert(xy[i]);
        outliers.insert(yx[i]);
    }
    int ans = INT_MAX;
    for (auto& e1 : outliers){
        for (auto& e2: outliers){
            for (auto& e3 : outliers){
                int minX = INT_MAX, maxX = -1, minY = INT_MAX, maxY = -1;
                for (int i = 0; i < n; i++){
                    if (xy[i] != e1 && xy[i] != e2 && xy[i] != e3){
                        minX = min(minX, xy[i].first); maxX = max(maxX, xy[i].first);
                        minY = min(minY, xy[i].second); maxY = max(maxY, xy[i].second);
                    }
                }
                ans = min(ans, (maxX - minX) * (maxY - minY));
            }
        }
    }
    //cout << 'h';
    cout << ans;
        
    
}