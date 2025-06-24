#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
bool check(vector <pair <int, int>>& dists, int& midIdx, int& dis, vector <int>& f){
    int maxDist = 0, curDist = 0;
    int n = f.size();
    for (int i = 0; i < n; i++){
        if (f[i] > dists[midIdx].first){
            curDist++;
        } else{
            curDist = 0;
        }
        maxDist = max(maxDist, curDist);
    }
    return (dis > maxDist ? true : false);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("snowboots");
    int n, b;
    cin >> n >> b;
    vector <int> f(n);
    //runs in O(n^2 log b)
    //got 4/12 test cases (3/11) * 333
    for (int i = 0; i < n; i++){
        cin >> f[i];
    }
    vector <vector <pair <int, int>>> dists(n);
    vector <bool> ans(b, 0);
    vector <int> workIndex(n, INT_MAX);
    vector <pair <int, int>> boots(b);
    for (int i = 0; i < b; i++){
        int si, di;
        cin >> si >> di;
        boots[i] = {si, di};
        dists[di].push_back({si, i});
    }
    for (int i = 0; i < n; i++){
        sort(dists[i].begin(), dists[i].end());
    }
    //now idea is just binary search for time complexity of O(n * log n)

    for (int i = 0; i < n; i++){
        int l = 0, r = dists[i].size() - 1;
        while (l <= r){
            int mid = l + (r - l)/2;
            if (check(dists[i], mid, i, f)){
                //WORKS AT THIS INDEX
                r = mid - 1;
                workIndex[i] = min(workIndex[i], mid);
            } else{
                l = mid + 1;
            }
        }        
    }
    /*for (int i = 0; i < n; i++){
        for (int j = 0; j < dists[i].size(); j++){
            ans[dists[i][j].second] = (j >= workIndex[i] ? true : false);
        }
    }*/
    for (int i = 0; i < b; i++){
        //boots [i]
        if (workIndex[boots[i].second] == INT_MAX){
            cout << 0;
        } else{
            cout << (dists[boots[i].second][workIndex[boots[i].second]].first <= boots[i].first ? 1 : 0);
        }
        cout << "\n";
    }

}