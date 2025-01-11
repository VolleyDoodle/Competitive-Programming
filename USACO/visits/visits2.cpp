#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    ll n;
    cin >> n;
    vector <pair <ll, ll>> graph(n + 1);
    vector <ll> visited(n + 1, 0);
    for (ll i = 1; i <= n; i++){
        cin >> graph[i].f >> graph[i].s;
    }
    //every node has exactly outgoing edge
    ll ans = 0;
    for (ll i = 1; i <= n; i++){
        if (!visited[i]){
            //bfs
            set <ll> visNodes;
            queue <ll> q;
            q.push(i);
            while (!q.empty()){
                ll cur = q.front();
                q.pop();
                visNodes.insert(cur);
                visited[cur]++;
                ans+=graph[cur].s;
                if (visNodes.count(graph[cur].f)){
                    //cycle
                    queue <ll> cycle;
                    cycle.push(graph[cur].f);
                    ll curMin = LONG_LONG_MAX;
                    while (!cycle.empty()){
                        ll curCyc = cycle.front();
                        cycle.pop();
                        visited[curCyc]++;
                        curMin = min(curMin, graph[curCyc].s);
                        if (visited[graph[curCyc].f] == 1){
                            cycle.push(graph[curCyc].f);
                        }
                    }
                    ans -= curMin;
                } else if (!visited[graph[cur].f]){
                    //ans+=graph[cur].s;
                    q.push(graph[cur].f);
                }

            }
        }
    }
    cout << ans;
    
}