#include <bits/stdc++.h>
using namespace std;
int n, k, gCount;
vector <pair <int, int>> swapLoc;
vector <int> finalLoc, graph, group;
vector <set <int>> groupPos, posVisited;
void dfs(int curNode){
    group[curNode] = gCount;
    groupPos[gCount].insert(posVisited[curNode].begin(), posVisited[curNode].end());
    if (!group[graph[curNode]]){
        dfs(graph[curNode]);
    }
}
int main(){
    cin >> n >> k;

    swapLoc.resize(k);
    finalLoc.resize(n + 1);
    graph.resize(n + 1);
    posVisited.resize(n + 1);
    group.resize(n + 1);
    fill(group.begin(), group.end(), 0);


    for (int i = 1; i <= n; i++) {
        finalLoc[i] = i;
        posVisited[i].insert(i);
    }

    for (int i = 0; i < k; i++){
        cin >> swapLoc[i].first >> swapLoc[i].second;
        posVisited[finalLoc[swapLoc[i].first]].insert(swapLoc[i].second);
        posVisited[finalLoc[swapLoc[i].second]].insert(swapLoc[i].first);
        swap(finalLoc[swapLoc[i].second], finalLoc[swapLoc[i].first]);
    }
    for (int i = 1; i <= n; i++){
        graph[finalLoc[i]] = i;
    }
    gCount = 1;
    groupPos.push_back({});
    for (int i = 1; i <= n; i++){
        if (!group[i]){
            groupPos.push_back({});
            dfs(i);
            gCount++;
        }
    }
    for (int i = 1; i <= n; i++){
        cout << groupPos[group[i]].size() << "\n";
    }

}