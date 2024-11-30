#include <bits/stdc++.h>
using namespace std;
vector <int>::iterator ownLowerBoundFn(vector <int> &nums, int x, int n){
    int l = 0, r = n - 1;
    int minMaxNum = INT_MAX, ans;
    while (r >= l){
        int mid = l + (r - l)/2;
        //if (nums[mid] == x){
            //return nums[mid];
        if (nums[mid] >= x){
            if (nums[mid] <= minMaxNum){
                minMaxNum = nums[mid];
                ans = mid;
            }
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    return nums.begin() + ans;
}

int main(){
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c, n, ans = 0, curCow = 0;
    cin >> c >> n;
    vector <int> chickens(c);
    vector <pair <int, int>> cows(n);
    vector <bool> cowsTaken(n);
    fill(cowsTaken.begin(), cowsTaken.end(), 0);
    for (int i = 0; i < c; i++){
        cin >> chickens[i];
    }
    for (int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(chickens.begin(), chickens.end(),[](int &x, int &y){return x < y;});
    sort(cows.begin(), cows.end(), [](auto x, auto y){return x.second < y.second;});
    for (int i = 0; i < n; i++){
        //sol with own lower_bound function (missed two tests cases)
       /* auto potChick = ownLowerBoundFn(chickens, cows[i].first, chickens.size());
        if (potChick != chickens.end() && *potChick <= cows[i].second){
            ans++;
            chickens.erase(potChick);
        }*/
        //all commented code works just exploring smarter answers
        /*for (int x = 0; x < n; x++){
            if (cows[x].first <= chickens[i] && chickens[i] <= cows[x].second && !cowsTaken[x]){
                ans++;
                cowsTaken[x] = true;
                break;
            }
        }*/

        auto potChick = lower_bound(chickens.begin(), chickens.end(), cows[i].first);
        if (potChick != chickens.end() && *potChick <= cows[i].second){
            ans++;
            chickens.erase(potChick);
        }
        

    }
    cout << ans;
}   