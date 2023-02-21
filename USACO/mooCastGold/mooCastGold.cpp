#include <bits/stdc++.h>
using namespace std;
int n;
vector <pair <int, int>> cords;
vector <bool> visited;
int vis = 0;
//basically first find x and then simulate to see if all cows are reached 
void find(int cur, int x){
    for (int i = 0; i < n; i++){
        int dist_sq = pow(cords[cur].first - cords[i].first, 2) +  pow (cords[cur].second - cords[i].second, 2);
        if (x >= dist_sq && !visited[i]){
            vis++;
            visited[i] = true;
            find(i, x);
        }
    }
}
bool check(int x){
    fill(visited.begin(), visited.end(), 0);
    vis = 1;
    visited[0] = true;
    find(0, x);
    /*if (vis == n){
        vis = 0;
        return true;
    }
    return false;*/
    return (vis == n) ? true: false;

}
int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int ans = INT_MAX; cin >> n;

    cords.resize(n); visited.resize(n);
    for (int i = 0; i < n; i++){
        cin >> cords[i].first >> cords[i].second;
    }
    int r = 1250000000, l = 0;

    while ( l <= r){
        int mid = l + (r - l)/2;
        if (check(mid)){
            ans = min(ans, mid);
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    cout << ans;
}