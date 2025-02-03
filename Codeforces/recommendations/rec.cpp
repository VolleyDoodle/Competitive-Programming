#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

void sweep(vector <vector <int>>& events, vector <ll>& ans, vector <pair <int, int>>& ids){
    multiset <int> ls;
    for (int i = 0; i < events.size(); i++){
        vector <int> event = events[i];
        if (event[1] == 0){
            //left
            ls.insert(event[0]);
        } else{
            //right
            vector <int> valsToErase;
            while (i < events.size() && events[i][0] == event[0] && events[i][1] == event[1]){
                ls.erase(ls.find(ids[events[i][2]].f));
                auto it = ls.upper_bound(ids[events[i][2]].f);
                
                if (it != ls.begin()){
                    it--;
                    ans[events[i][2]]+= abs(ids[events[i][2]].f - *it);
                }
                ls.insert(ids[events[i][2]].f);
                valsToErase.push_back(ids[events[i][2]].f);
                i++;
            }
            i--;
            for (int val : valsToErase){
                ls.erase(ls.find(val));
            } 
        }
    }
}
void solve(){
    int n;
    cin >> n;
    vector <vector <int>> intervals(n, vector <int>(3));
    vector <ll> ans(n, 0);
    vector <pair <int, int>> ids(n);
    vector <bool> can(n, true);
    for (int i = 0; i < n; i++){
        cin >> intervals[i][0] >> intervals[i][1];
        intervals[i][2] = i;
        ids[i] = make_pair(intervals[i][0], intervals[i][1]);
    }
    sort(intervals.begin(), intervals.end());
    vector <vector <int>> events;
    /*for (int i = 0; i < n - 1; i++){
        if (intervals[i][0] == intervals[i + 1][0] && intervals[i][1] == intervals[i + 1][1]){
            can[intervals[i][2]] = false;
            can[intervals[i + 1][2]] = false;
        }
        
    }*/
    for (int i = 0; i < n; i++){
        if (can[i]){
            events.push_back({intervals[i][0], 0, intervals[i][2]});
            events.push_back({intervals[i][1], 1, intervals[i][2]});
        }
    }
    sort(events.begin(), events.end());
    sweep(events, ans, ids);
    //now do some swapping
    vector <vector <int>> events2;
    //now the rights are going to become -right and the "left"
    //and the lefts and going to become -lefts and the "right"
    for (int i = 0; i < n; i++){
        swap(ids[i].f, ids[i].s);
        ids[i].f*=-1; ids[i].s*=-1;
        events2.push_back({ids[i].f, 0, i});
        events2.push_back({ids[i].s, 1, i});
    }
    sort(events2.begin(), events2.end());
    sweep(events2, ans, ids);
    for (ll& a : ans){
        cout << a << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}