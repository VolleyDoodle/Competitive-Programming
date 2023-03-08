#include <bits/stdc++.h>
using namespace std;
int n, m;
const int bigNum = 1e5 + 2;
int curRoot = 0;
vector <int> graph[bigNum], connected[bigNum];
int roots[bigNum];

void dfs(int node ){
    roots[node] = curRoot;
    for (int curNode: graph[node]){
        if (!roots[curNode]){
            dfs(curNode);
        }  
    }
}
long long cost(int connector){
    //connect component 1 to connector
    //and connect connecter to component[curRoot] (what ever component farm n is in)
    int valS = INT_MAX, valE = INT_MAX;
    for (int curFarm : connected[connector]){
        auto startIt = upper_bound(connected[1].begin(), connected[1].end(), curFarm);
        auto endIt = upper_bound(connected[roots[n]].begin(), connected[roots[n]].end(), curFarm);
        if (startIt != connected[1].end()){
            valS = min(valS, abs((*startIt) - curFarm));
        } if (startIt != connected[1].begin()){
            startIt--;
            valS = min(valS, abs((*startIt) - curFarm));
        }
        if (endIt != connected[roots[n]].end()){
            valE = min(valE, abs((*endIt) - curFarm));
        } if (endIt != connected[roots[n]].begin()){
            endIt--;
            valE = min(valE, abs((*endIt) - curFarm));
        }
    }
    return (1LL * valS * valS) + (1LL * valE * valE);
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        roots[i] = 0;
        graph[i].clear(); 
        connected[i].clear();
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    curRoot = 0;
    for (int i = 1; i <= n; i++){
        
        if (!roots[i]){ //if roots = 0
            curRoot++;
            dfs(i);
            //++i = returns value after adding, i++ = returns value before adding
        }
    }
    //basically above code gives "id" to each group of roots farm
    //(more efficient than actually creating vector of vector that holds all roots components within)
    //as then we will have to do that for every element in that connection
    //instead we do it for every "id"
    //O(n^2) algo then (which is too slow)
    //now all we have to do is check all of the roots components w/ each other
    //(but idk how to do that)
    for (int i = 1; i <= n; i++){
        connected[roots[i]].push_back(i);
    }
    long long ans = cost(1);
    for (int i = 1; i <= curRoot; i++){
        ans = min(ans, cost(i));
    }
    //cout << "h";
    cout << ans << "\n";

}

int main(){
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        solve();
    }
}