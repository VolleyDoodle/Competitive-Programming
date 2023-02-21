#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> graph;
vector <int> visited;
void dfs(int node){

}
void solve(){
    int p, c; cin >> p >> c;
    if (p == 0 && p == c){return; }
    graph.resize(p); visited.resize(p);
    fill()
    for (int i = 0; i < c; i++){
        int t, tt; cin >> t >> tt;
        graph[t].push_back(tt); graph[tt].push_back(t);
    }
    dfs(0);


}
int main(){
    solve();
}