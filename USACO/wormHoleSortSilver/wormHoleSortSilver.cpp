#include <bits/stdc++.h>
using namespace std;
vector <int> nums;
vector <bool> visited;
vector <vector <pair <int, int>>> wormholes;
int vis = 0, mid, needToSwap = 0;

void dfs(int node){
    visited[node] = true;

    for (auto wormhole: wormholes[node]){
        if (!visited[wormhole.first] && wormhole.second >= mid){
            if (wormhole.first != nums[wormhole.first]){
                vis++;
            }
            dfs(wormhole.first);
        }
    }
}
bool check(){
    for (int i = 1; i <= nums.size(); i++){
        if (i != nums[i]){
            dfs(nums[i]);
            break;
        }
    }
    return (vis == needToSwap ? true: false);
}
int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int ans = -1;
    nums.resize(n + 1);
    wormholes.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
        if (i != nums[i]){needToSwap++;}
    }
    for (int i = 1; i <= m; i++){
        int t, tt, ttt; cin >> t >> tt >> ttt;
        wormholes[t].push_back({tt, ttt});
        wormholes[tt].push_back({t, ttt});

    }
    //binary search answer and see if we can access all incorrectly placed cows
    //if so then this is a possible solution
    int r = pow(10, 9), l = 0;
    while ( l <= r){
        mid = l + (r - l)/2;
        fill(visited.begin(), visited.end(), 0);
        vis = 1;
        if (check()){
            ans = max(ans, mid);
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    cout << ans;

    
}