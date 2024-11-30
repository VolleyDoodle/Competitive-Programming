#include <bits/stdc++.h>
using namespace std;
int n, m, k, group = 1;
vector <int> sim, posAfterM, visited;
vector <vector <int>> cycleLen;
vector <pair <int, int>> lr;
void dfs(int parent){
    cycleLen[group].push_back(parent);
    visited[parent] = group;
    if (!visited[posAfterM[parent]]){
        dfs(posAfterM[parent]);
    }
}
int main(){

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    cin >> n >> m >> k;

    visited.resize(n + 1);
    sim.push_back(0); lr.resize(m);
    posAfterM.resize(n + 1);
    cycleLen.push_back({});
    fill(visited.begin(), visited.end(), 0);

    for (int i = 0; i < m; i++){
        cin >> lr[i].first >> lr[i].second;
    }
    for (int i = 1; i <= n; i++){sim.push_back(i);}
    //simulate one m process
    for (auto curLR : lr){
        reverse(sim.begin() + curLR.first, sim.begin() + curLR.second + 1);
    }
    //cout << "ogga";
    for (int i = 1; i <= n; i++){
        posAfterM[sim[i]] = i;
    }
    //cout << "ogga";
    
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cycleLen.push_back({});
            dfs(posAfterM[i]);
            group++;
        }
    }
    //cout << "ogga";
    vector <int> ans(n + 1), nAns(n + 1);
    for (int i = 1; i < group; i++){
        for (int x = 0; x < cycleLen[i].size(); x++){
            //cout << cycleLen[i][(x + k%cycleLen[i].size()) % cycleLen[i].size()];
            ans[cycleLen[i][x]] = cycleLen[i][(x + k%cycleLen[i].size()) % cycleLen[i].size()];
        }
    }
    for (int i = 1; i <= n; i++){
        nAns[ans[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        cout << nAns[i] << '\n';
    }
}