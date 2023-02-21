#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector <int> cities(n), towers(m);
    for (int i = 0; i < n; i++){
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++){
        cin >> towers[i];
    }
    int r = INT_MIN, cur_r = 0;
    int prevTower = INT_MIN;

    //cout << towers.end() - towers.begin(); prints n (so points out of vector)
    //cout << towers[lower - towers.begin()] << "\n";
    int ans = INT_MIN;
    for (int i = 0; i < n; i++){
        //to the right
        int curAns = INT_MAX;
        vector<int>::iterator right = lower_bound(towers.begin(), towers.end(), cities[i]);
        if (right != towers.end()){
            int rightVal = towers[right - towers.begin()];
            curAns = rightVal - cities[i];
        } else{
            curAns = cities[i] - towers[m - 1];
        }
        if(right != towers.begin() && right != towers.end()){
            curAns = min(curAns, cities[i] - towers[right - towers.begin() - 1]);
        }
        ans = max(ans, curAns);
    }
    cout << ans << "\n";

}