#include <bits/stdc++.h>
using namespace std;
int n, k, ans = INT_MAX;
vector <int> cows;
bool check(int r){
    int curK = 0;
    auto curCowVal = cows.begin();
    while (curK < k){
        int temp = *curCowVal;
        temp+=2 * r;
        curCowVal = upper_bound(cows.begin(), cows.end(), temp);
        curK++;
        if (curCowVal == cows.end()){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    cows.resize(n);
    for (int i = 0; i < n; i++){
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    int l = 0,  r = cows[n - 1] + 1;
    while (l <= r){
        int mid = l + (r - l)/2;
        //mid is cur R value
        if (check(mid)){
            ans = min(ans, mid);
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    cout << ans;
    

}