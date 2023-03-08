#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = LLONG_MAX, curAns = LLONG_MAX;
long long total;
vector <pair <int, int>> cows;
vector <int> areas;
//basically for areas 
// areas[1] = (maxY - minY) of cows[n - 1]...cows[n - 1] (basically only 1 element in 2nd enclosure)
//areas[2] = (2 elements in 2nd enclosure) -> (maxY - minY) of cows[n - 1]...cows[n - 2]
//areas[5] = (5 elements in 2nd enclosure) -> (maxY - minY) of cows[n - 1]...cows[n - 5];
void solve(){
    sort(cows.begin(), cows.end());
    //cout << cows[0].first << '\n';
    //cout << cows[n - 1].first << "\n";
    int minYSecond = INT_MAX, maxYsecond = INT_MIN;
    for (int i = n - 1; i >= 0; i--){
        minYSecond = min(minYSecond, cows[i].second);
        maxYsecond = max(maxYsecond, cows[i].second);
        areas[i] = maxYsecond - minYSecond;
    }
    total = (1LL) * (cows[n - 1].first - cows[0].first) * areas[0];
    int maxYfirst = cows[0].second, minYfirst = maxYfirst;
    for (int i = 1; i < n; i++){
        //find min and max x and y cords efficiently for other cords
        
        if (cows[i].first != cows[i - 1].first){
            long long firstEnclosureArea = (1LL) * (cows[i - 1].first - cows[0].first) * (maxYfirst - minYfirst);
            long long secondEnclosureArea = (1LL) * (cows[n - 1].first - cows[i].first) * (areas[i]);
            curAns = firstEnclosureArea + secondEnclosureArea;
            ans = min(ans, curAns);
        }
            
        minYfirst = min(minYfirst, cows[i].second); maxYfirst = max(maxYfirst, cows[i].second);
    }
}
int main(){
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cows.resize(n);
    areas.resize(n);
    for (int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    
    solve();

    for (int i = 0; i < n; i++){
        swap(cows[i].first, cows[i].second);
    }
    solve();
    long long fans = total - ans;
    cout << fans;
}