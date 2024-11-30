#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> roads;
vector <bool> visited;
vector <int> build;
void dfs(int curNode){
    for (long i = 0; i < roads[curNode].size(); i++){
        if (!visited[roads[curNode][i]]){
            //node has not been visited
            visited[roads[curNode][i]] = true; 
            dfs(roads[curNode][i]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    roads.resize(n + 1); visited.resize(n + 1);
    for (int i = 0; i < m; i++){
        int r1, r2; cin >> r1 >> r2;
        
        roads[r1].push_back(r2); roads[r2].push_back(r1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        
        if (!visited[i]){
            //if (ans == 0) {root = i;}
            build.push_back(i);
            //node has not been visited yet and do dfs
            ans++;
            dfs(i);
        }
       
    }
    cout << ans - 1 << "\n";
    for (long i = 1; i < build.size(); i++){
        cout << i << " " << build[i] << "\n";
    }

}