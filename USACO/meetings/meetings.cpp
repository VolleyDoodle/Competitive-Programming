#include <bits/stdc++.h>
using namespace std;
struct cow{
    int w, x, d;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    int n, l;

    cin >> n >> l;
    vector <cow> cows(n), rightBarnCows;
    vector <pair <int, int>> timeWeight;
    vector <int> rightTimes, leftTimes, rightVelocityCows, leftVelocityCows;
    
    
    int wSum = 0;
    for (int i = 0; i < n; i++){
        cin >> cows[i].w >> cows[i].x >> cows[i].d;
        wSum+=cows[i].w;
    }
    sort(cows.begin(), cows.end(), [](const auto& a, const auto& b){
        return a.x < b.x;
    });
    for (cow element : cows){
        if (element.d == 1){
            rightTimes.push_back(l - element.x);
            rightVelocityCows.push_back(element.x);
        } else{
            leftTimes.push_back(element.x);
            leftVelocityCows.push_back(element.x);
        }
    }
    for (int i = 0; i < leftTimes.size(); i++){
        timeWeight.push_back({leftTimes[i], cows[i].w});
    }
    for (int i = 0; i < rightTimes.size(); i++){
        timeWeight.push_back({rightTimes[i], cows[leftTimes.size() + i].w});
    }
    sort(timeWeight.begin(), timeWeight.end());
    int cWeight = 0, u = 0;
    while (cWeight * 2 < wSum){
        cWeight+=timeWeight[u].second;
        u++;
    }
    u--;
    int T = timeWeight[u].first;
    //find colliseoins
    //for (int i = 0; i < ri)
    sort(leftVelocityCows.begin(), leftVelocityCows.end());
    int ans = 0;
    for (int i = 0; i < rightVelocityCows.size(); i++){
        ans+=lower_bound(leftVelocityCows.begin(), leftVelocityCows.end(), rightVelocityCows[i] + 2 * T) - 
        lower_bound(leftVelocityCows.begin(), leftVelocityCows.end(), rightVelocityCows[i]);
    }
    cout << ans;

}