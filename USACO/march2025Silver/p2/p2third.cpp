#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    ll n, a, b;
    cin >> n >> a >> b;
    //vector <pair <ll, ll>> nums(n);
    map <ll, ll> cows;
    map <ll, vector <ll>> graph;
    map <ll, bool> visited;
    for (ll i = 0; i < n; i++){
        ll ni, di;
        cin >> ni >> di;
        cows[di] = ni;
        visited[di] = false;
    }
    for (auto& p : cows){
        if (cows.count(a - p.first) && p.first != (a - p.first)){
            graph[p.first].push_back(a - p.first);
        }
    }
    if (a != b){
        for (auto& p : cows){
            if (cows.count(b - p.first) && p.first != (b - p.first)){
                graph[p.first].push_back(b - p.first);
            }
        }
    }
    //now we have a graph
    vector <ll> startVals;
    for (auto& p : graph){
        if (p.second.size() == 1){
            startVals.push_back(p.first);
        }
    }
    ll ans = 0;
    for (ll num : startVals){
        if (!visited[num]){
            //bfs
            queue <ll> q;
            q.push(num);
            while (!q.empty()){
                ll cur = q.front();
                q.pop();
                visited[cur] = true;
                for (ll nxtNode : graph[cur]){
                    if (!visited[nxtNode]){
                        ll amt = min(cows[nxtNode], cows[cur]);
                        ans += amt;
                        cows[nxtNode]-=amt;
                        cows[cur]-=amt;
                        q.push(nxtNode);
                    }
                }
            }
        }
    }

    for (auto& p : cows){
        if (cows.count(a - p.first)){
            if (p.first == a - p.first){
                ll amt = cows[p.first];
                amt = (amt / 2);
                ans += amt;
                amt*=2;
                cows[a - p.first]-=amt;
                continue;
            }
        }
    }
    swap(a, b);
    for (auto& p : cows){
        if (cows.count(a - p.first)){
            if (p.first == a - p.first){
                ll amt = cows[p.first];
                amt = (amt / 2);
                ans += amt;
                cows[a - p.first]-=amt;
                continue;
            }
        }
    }
    cout << ans;
}