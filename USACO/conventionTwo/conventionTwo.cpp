#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n;
    cin >> n;
    vector <vector <int>> cows(n, vector<int>(3));
    for (int i = 0; i < n; i++){
        cin >> cows[i][0] >> cows[i][1];
        cows[i][2] = i;
    }
    sort(cows.begin(), cows.end());
    cows.push_back({INT_MAX, INT_MAX, -1});
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <>> cowsInLine;

    long long endTime = cows[0][0] + cows[0][1];
    long long ans = 0, curCow = 1;
    while (curCow <= n){
        if (endTime >= cows[curCow][0]){
            cowsInLine.push({cows[curCow][2], curCow});
            curCow++;
            
        } else{
            //cows[curCow][0] < endTime
            //so first in pq now goes :)))
            ans = max(ans,endTime - cows[cowsInLine.top().second][0]);
            endTime+= cows[cowsInLine.top().second][1];
            cowsInLine.pop();
            if (cowsInLine.empty() && endTime < cows[curCow][0]){
                //if (curCow == n) break;
                endTime = cows[curCow][0];
            }
        }
    }

    cout << ans;

}