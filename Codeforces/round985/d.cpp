#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
//sometimes codeforces statements are just fucking not clear
//and that makes me angry

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector <set <int>> graph(n + 1);
    vector <vector <int>> ans;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    for (int i = 1; i <= n; i++){
        while (graph[i].size() >= 2){
            //lets say i = a,
            int b = *graph[i].begin();
            graph[i].erase(graph[i].begin());
            graph[b].erase(i);
            int c = *graph[i].begin();
            graph[i].erase(graph[i].begin());
            graph[c].erase(i);
            //check for edge of b, c
            if (graph[b].count(c) > 0){
                graph[b].erase(c);
                graph[c].erase(b);
            } else{
                graph[c].insert(b);
                graph[b].insert(c);
            }
            ans.push_back({i, b, c});
        }
    }
    //making everything into a singular node, or a line segment look-alike
    //now just have to add everthing together
    int a = -1, temp = -1;
    for (int i = 1; i <= n; i++){
        if (graph[i].size() == 1){
            a = i;
            temp = *graph[i].begin();
            graph[temp].insert(-1);
            graph[i].insert(-1);
            break;
        }
    }
    if (a != -1){
        for (int i = 1; i <= n; i++){
            if (graph[i].size() == 1){ 
                int temp2 = *graph[i].begin();
                ans.push_back({a, i, temp2});
                graph[i].insert(-1);
                graph[temp2].insert(-1);
            } else if (graph[i].size() == 0){
                ans.push_back({a, temp, i});
                temp = i;
            }
        }
    }
    
    cout << ans.size() << "\n";
    for (vector <int>& v : ans){
        cout << v[0] << " " << v[1] << " " << v[2] << "\n";
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