#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <pair <long long, long long>> intervals;
bool check(long long D){
    int curIntervalIndex = 0, currentCowsFit = 1;
    bool atLeastOnce = false;
    long long locLastCow = intervals[curIntervalIndex].first;
    while (curIntervalIndex < m){
        //all possible cows that can fit in this interval
        
        if (intervals[curIntervalIndex].second >= locLastCow + D){
            //this cow can fit in current interval
            if (locLastCow + D <= intervals[curIntervalIndex].first){
                locLastCow = intervals[curIntervalIndex].first;
            } else{
                atLeastOnce = true;
                locLastCow += D;
            }
            currentCowsFit++;
            if (currentCowsFit == n){
                return atLeastOnce;
            }
        } else{
            curIntervalIndex++;
        }
    }
    return false;
}
int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    intervals.resize(m);
    for (int i = 0; i < m; i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end(), []
        (auto const& a, auto const& b){      
        return a.first < b.first;
    });
    long long ans = -1;
    long long lo = 1, hi = 1e18;

    while (lo <= hi){
        long long mid = lo + (hi - lo)/2;
        if (check(mid)){
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans;
}