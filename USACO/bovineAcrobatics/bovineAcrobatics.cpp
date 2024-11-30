#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    // i like my cheese drippy bruh
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    cin >> n >> m >> k;
    vector <pair <int, int>> cows(n);
    for (int i = 0 ; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
        cows[i].second = min(m, cows[i].second);
    }
    long long ans = 0;
    sort(cows.begin(), cows.end());
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater<>> pq;
    pq.push({-1e9, m});
    int iterCount = 0;
    for (int i = 0; i < n; i++){
        auto curCow = cows[i];
        int totalAmtToTake = 0, amtToTake = 0;
        pair <int, int> curTowers;
        while (pq.size() && curCow.first - k >= pq.top().first && curCow.second > 0){
            //case 1 #of cows bigger than top of pq
            //case 2 #of cows smaller than top of pq
            //iterCount++;
            curTowers = pq.top(); pq.pop();
            //cout << "inf loop" << curCow.second << " " << curTowers.second;
            amtToTake = min(curCow.second, curTowers.second);
            ans+=amtToTake;
            totalAmtToTake += amtToTake;
            curCow.second -= amtToTake;


            /*if (curCow.second >= curTowers.second){
                pq.push({curCow.first, curTowers.second});
                ans+=curTowers.second;
                curCow.second-=curTowers.second;
            } else if (curCow.second < curTowers.second){
                pq.push({curCow.first, curCow.second});
                pq.push({curTowers.first, curTowers.second - curCow.second});
                ans+=curCow.second;
                curCow.second = 0;
            }*/
            
            
        }
        pq.push({curCow.first, totalAmtToTake});
        if (amtToTake < curTowers.second) pq.push({curTowers.first, curTowers.second - amtToTake});
        //cout << iterCount << "\n";
    }
    //cout << iterCount;
    cout << ans;
}