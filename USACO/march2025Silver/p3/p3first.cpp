#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
vector <vector <vector <ll>>> graph;
vector <vector <ll>> endpts;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void doProc(ll cur, vector <pair <ll, multiset <ll>>>& waypoints, vector <ll> path){
    bool done = true;
    path.push_back(cur);
    for (vector <ll>& v : graph[cur]){
        done = false;
        waypoints[v[0]].f = waypoints[cur].f + v[2];
        waypoints[v[0]].s.insert(v[1]);
        for (ll ele : waypoints[cur].s){
            waypoints[v[0]].s.insert(ele);
        }
        while (waypoints[v[0]].s.size() > 15){
            waypoints[v[0]].s.erase(waypoints[v[0]].s.begin());
        }
        doProc(v[0], waypoints, path);
    }
    if (done){
        endpts.push_back(path);
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
    vector <ll> path;
    waypoints[1].f = 0;
    doProc(1, waypoints, path);
    ll m;
    cin >> m;
    vector <ll> ans(m, 0);
    for (ll i = 0; i < m; i++){
        ll sj, cj;
        cin >> sj >> cj;
        for (ll x = 1; x <= n; x++){
            auto it = waypoints[x].s.upper_bound(sj);
            ll amt = distance(it, waypoints[x].s.end());
            if (amt <= cj){
                ans[i] = max(ans[i], waypoints[x].f);
            }
        }
    }
    for (ll i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
    //cout << "h";
}