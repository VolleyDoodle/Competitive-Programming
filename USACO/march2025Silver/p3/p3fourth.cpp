#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
vector <vector <vector <ll>>> graph;
vector <ll> cjs, sjs;
vector <map <ll, ll>> cnt;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void doProc(ll cur, vector <pair <ll, multiset <ll>>>& waypoints){
    if (waypoints[cur].s.size() > 0){
        ll idx = 0;
        auto it2 = prev(waypoints[cur].s.end());
        auto it = lower_bound(sjs.begin(), sjs.end(), *it2);

        while (idx < 11){
            it = lower_bound(sjs.begin(), sjs.end(), *it2);
            if (it != sjs.end()){
                ll val = *it;
                cnt[idx][val] = max(cnt[idx][val], waypoints[cur].f);
            }
            if (it2 == waypoints[cur].s.begin()){
                break;
            }
            it2 = prev(it2);
            idx++;
        }  
        for (int i = idx + 1; i <= 10; i++){
            cnt[i][sjs[0]] = max(waypoints[cur].f, cnt[i][sjs[0]]);
        }  
    }
    
    
    for (vector <ll>& v : graph[cur]){
        waypoints[v[0]].f = waypoints[cur].f + v[2];
        waypoints[v[0]].s.insert(v[1]);
        for (ll ele : waypoints[cur].s){
            waypoints[v[0]].s.insert(ele);
        }
        while (waypoints[v[0]].s.size() > 15){
            waypoints[v[0]].s.erase(waypoints[v[0]].s.begin());
        }
        doProc(v[0], waypoints);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    ll n;
    cin >> n;
    vector <pair <ll, multiset <ll>>> waypoints(n + 1);
    //enjoyment, 10 most difficult slopes
    graph.resize(n + 1);

    for (ll i = 2; i <= n; i++){
        ll pi, di, ei;
        cin >> pi >> di >> ei;
        graph[pi].push_back({i, di, ei});
    }
    
    ll m;
    cin >> m;
    vector <ll> ans(m, 0);
    cnt.resize(11);
    vector <ll> copysjs;
    for (ll i = 0; i < m; i++){
        ll sj, cj;
        cin >> sj >> cj;
        cjs.push_back(cj);
        sjs.push_back(sj);
        for (int x = 0; x < 11; x++){
            cnt[x][sj] = 0;
        }
    }
    copysjs = sjs;
    sort(sjs.begin(), sjs.end());
    waypoints[1].f = 0;
    doProc(1, waypoints);
    ll maxVal = 0;
    for (int i = 0; i < 11; i++){
        maxVal = 0;
        for (auto& p : cnt[i]){
            maxVal = max(p.second, maxVal);
            cnt[i][p.first] = maxVal;
        }
    }
    
    for (ll i = 0; i < m; i++){
        ll sj, cj;
        sj = copysjs[i];
        cj = cjs[i];
        ans[i] = cnt[cj][sj];
        continue;
    }
    for (ll i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
    //cout << "h";
}