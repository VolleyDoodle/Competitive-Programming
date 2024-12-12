#include <bits/stdc++.h>
using namespace std;
//fucking did this problem wrong
//also made it alot easier than its supposed to be
//8/15 test cases O(n^2)
void solve(){
    long long n, x1;
    cin >> n >> x1;
    vector <long long> leftPoints;
    vector <pair <long long, long long>> needNeg(n), needPos(n);
    for (long long i = 0; i < n; i++){
        long long y1;
        cin >> y1 >> needNeg[i].second >> needNeg[i].first;
        needPos[i].first = needNeg[i].first;
        needPos[i].second = y1;
        leftPoints.push_back(y1);
        leftPoints.push_back(needNeg[i].second);
    }
    vector <long long> posSlopes, negSlopes;
    for (long long i = 0; i < 4 * n; i++){
        long long t1;
        cin >> t1;
        (t1 > 0 ? posSlopes.push_back(t1) : negSlopes.push_back(t1));
    }
    if (posSlopes.size() < n || negSlopes.size() < n){
        cout << "-1";
        return;
    }
    //needNeg Points need neg slopes
    //bottomLeft Points need pos slopes
    
    sort(leftPoints.begin(), leftPoints.end());
    for (long long i = 0; i < leftPoints.size(); i++){
        if (needNeg.size() < negSlopes.size()){
            needNeg.push_back({x1, leftPoints[i]});
        } else{
            needPos.push_back({x1, leftPoints[i]});
        }
    }
    sort(negSlopes.begin(), negSlopes.end());
    sort(posSlopes.begin(), posSlopes.end(), greater<>());
    long long upVal = LLONG_MIN, downVal = LLONG_MAX;
    for (long long i = 0; i < negSlopes.size(); i++){
        //for negative slopes, you want the minimum y-long longercept of all
        long long curMin = LLONG_MAX;
        long long curMinIndex;
        for (long long x = 0; x < needNeg.size(); x++){
            if ((needNeg[x].second - (needNeg[x].first * negSlopes[i])) < curMin){
                curMin = needNeg[x].second - (needNeg[x].first * negSlopes[i]);
                curMinIndex = x;
            }
        }
        upVal = max(upVal, curMin);
        needNeg.erase(needNeg.begin() + curMinIndex);
    }
    for (long long i = 0; i < posSlopes.size(); i++){
        //for pos slopes, you want the max y-long longercept of all
        long long curMax = LLONG_MIN;
        long long curMaxIndex;
        for (long long x = 0; x < needPos.size(); x++){
            if ((needPos[x].second - (needPos[x].first * posSlopes[i])) > curMax){
                curMax = needPos[x].second - (needPos[x].first * posSlopes[i]);
                curMaxIndex = x;
            }
        }
        downVal = min(downVal, curMax);
        needPos.erase(needPos.begin() + curMaxIndex);
    }
    cout << upVal - downVal;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    long long t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}