#include <bits/stdc++.h>
using namespace std;
int n, m, c;
bool check(int& maxTime, vector <int>& cows){
    int curIndex = 0, curCowsInBus = 1, startTime = cows[0];
    int tempMax = -1, busesLeft = m;
    while(curIndex < n && busesLeft > 0){
        //case 1, bus is completely full -> ship off cows
        //case 2, current cow's time makes the time more than allowed, ship off cur - 1
        //
        if (cows[curIndex] - startTime > maxTime){
            //ship off cows[curIndex - 1] and before
            tempMax = max(tempMax, cows[curIndex - 1] - startTime);
            busesLeft--;
            curCowsInBus = 1;
            startTime = cows[curIndex];
        }
        else if (curCowsInBus == c){
            //ship off!
            tempMax = max(tempMax, cows[curIndex] - startTime);
            curIndex++;
            if (curIndex == n) break;
            startTime = cows[curIndex];
            busesLeft--;
            curCowsInBus = 1;
        } else{
            curIndex++;
            curCowsInBus++;
        }
    }
    if (curIndex == n && busesLeft > 0){
        return true;
    } 
    return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n >> m >> c;
    vector <int> cows(n);
    for (int i = 0; i < n; i++){
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    int ans = INT_MAX;
    int lo = 0, hi = 1e9;
    while (lo <= hi){
        int mid = lo + (hi - lo)/2;
        if (check(mid, cows)){
            ans = mid;
            hi = mid - 1;
        } else{
            lo = mid + 1;
        }
    }
    cout << ans;
    
}