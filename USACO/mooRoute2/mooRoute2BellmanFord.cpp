#include <bits/stdc++.h>
using namespace std;
const int bigNum = 5;
vector <int> a(bigNum), flightsTo(bigNum);
vector <vector <int>> graph(bigNum);
map <pair <int, int>, vector <pair <int, int>> lookup;
//no idea, but this problem seems really hard for silver

void dfs1(int node){

}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, m;
    for (int i = 0; i < m; i++){
        int c, r, d, s;
        cin >> c >> r >> d >> s;
        graph[c].push_back(d);
        lookup[{c, d}].push_back({r, s});
    }
    for (int i = 1; i <= n; i++) cin >> a[i];

}