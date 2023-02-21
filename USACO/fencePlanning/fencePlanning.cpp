#include <bits/stdc++.h>
using namespace std;

vector <bool> visited;
vector <vector <int>> graph;
vector <pair <int, int>> cords;
int perimeter = INT_MAX, curPerimeter = INT_MAX;
int minY = INT_MAX, maxY = INT_MIN, minX = INT_MAX, maxX = INT_MIN;
void dfs(int node){
    for (int i = 0; i < graph[node].size(); i++){
        int curX = cords[graph[node][i]].first, curY = cords[graph[node][i]].second;
        minY = min(minY, curY); maxY = max(maxY, curY); minX = min(minX, curX); maxX = max(maxX, curX);
        //curPerimeter = min(curPerimeter, (maxY - minY) * (maxX - minX));
        if (!visited[graph[node][i]]){
            visited[graph[node][i]] = true;
            dfs(graph[node][i]);
        }
    }
}
int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    graph.resize(n + 1); visited.resize(n + 1); cords.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> cords[i].first >> cords[i].second;
    }
    for (int i = 0; i < m; i++){
        int t, tt; cin >> t >> tt;
        graph[t].push_back(tt); graph[tt].push_back(t);
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            visited[i] = true;
            dfs(i);
            if(maxY == minY){maxY++;} if (maxX == minX){maxX++;}
            perimeter = min(perimeter,(2 * (maxY - minY)) + (2 * (maxX - minX))); 
            curPerimeter = INT_MAX; 
            minY = INT_MAX, maxY = INT_MIN, minX = INT_MAX, maxX = INT_MIN;
        }
    }
    cout << perimeter;

}