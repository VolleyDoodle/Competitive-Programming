#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first 
#define s second
const ll bigNum = 1e5 + 2; //change to 1e5 + 2
vector <vector <pair <ll, ll>>> graph(bigNum);
vector <bool> visited(bigNum, false);
ll ans = 0, tempAns = 0;
ll curMin = LONG_LONG_MAX, start = -1;
//directed graph
void dfs(ll curNode){
    visited[curNode] = true;
    /*if (!visited[graph[curNode].f] || graph[curNode].f == start){
        curMin = min(curMin, graph[curNode].s);
        tempAns+=graph[curNode].s;
        dfs(graph[curNode].f);
    }*/
    for (auto& p : graph[curNode]){
        if (!visited[p.f] || p.f == start){
            curMin = min(curMin, p.s);
            tempAns+=p.s;
            dfs(p.f);
        } 
    }
       
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++){
        ll ai, vi;
        cin >> ai >> vi;
        graph[i].push_back({ai, vi});
    }

    for (ll i = 1; i <= n; i++){
        if (!visited[i]){
            start = i;
            tempAns = 0; curMin = LONG_LONG_MAX;
            dfs(i);
            ans += tempAns - curMin;
        }
    }
    cout << ans;
}