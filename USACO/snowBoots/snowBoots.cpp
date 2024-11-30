#include <bits/stdc++.h>
using namespace std;
vector <int> snowDepth;
vector <pair <int, int>> boots;
int ans = INT_MAX, n, b;
bool beenThere[251][251];
void solve(int curBootIndex, int curSnowIndex){
    if (beenThere[curBootIndex][curSnowIndex]) return;
    beenThere[curBootIndex][curSnowIndex] = true;
    
    if (curSnowIndex == n - 1){
        ans = min(curBootIndex, ans);
        return;
    }
    //try to go keep on going forward until no more
    for (int i = curSnowIndex + 1; i <= min(n - 1, curSnowIndex + boots[curBootIndex].second); i++){
        if (boots[curBootIndex].first >= snowDepth[i]){
            solve(curBootIndex, i);
        }
    }
    //switch boot if possible no matter what
    for (int i = curBootIndex + 1; i < b; i++){
        if (snowDepth[curSnowIndex] <= boots[i].first){
            solve(i, curSnowIndex);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> n >> b;
    snowDepth.resize(n);
    boots.resize(b);
    for (int i = 0; i < n; i++){
        cin >> snowDepth[i];
    }
    for (int i = 0; i < b; i++){
        cin >> boots[i].first >> boots[i].second;
    } //stores where we are currently at
    solve(0, 0);
    cout << ans;

}