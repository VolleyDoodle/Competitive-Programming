#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> graph;
vector <bool> visited;
int curAns;
void dfs(int node){
    visited[node] = true;
    for (int curNode : graph[node]){
        if (!visited[curNode]){
            curAns++;
            dfs(curNode);
        }
    }
}
class cow {
    public:
    int x, y;
    bool id;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector <cow> cows(n);
    vector <vector <int>> events;
    vector <int> dist(n, pow(10, 9) + 1);
    vector <bool> NorE(n);
    graph.resize(n); visited.resize(n);
    for (int i = 0; i < n; i++){
        char tType;
    
        cin >> tType >> cows[i].x >> cows[i].y;
        if (tType == 'N'){cows[i].id = true ? : cows[i].id = false;}
        //racism with north and east cows
    }
    //cout << "h";
    //below finds all possible events
    cow nCow, eCow;
    for (int i = 0; i < cows.size(); i++){
        for (int x = 0; x < cows.size(); x++){
            nCow = cows[i]; eCow = cows[x];
            if (!nCow.id || eCow.id) { continue;}
            if (eCow.y > nCow.y && nCow.x > eCow.x && nCow.x - eCow.x != eCow.y - nCow.y){
                //checking if plausible that two cows can interact and if they have not stopped
                int stopTime = max(nCow.x - eCow.x, eCow.y - nCow.y);
                events.push_back ({stopTime, i, x});
            }
        }
    }
    sort(events.begin(), events.end());
    //cout << 'h';
    for (auto event : events){
        nCow = cows[event[1]]; eCow = cows[event[2]];
        if (nCow.y + dist[event[1]] >= eCow.y && eCow.x + dist[event[2]] >= nCow.x){
            if (nCow.x - eCow.x > eCow.y - nCow.y){
                //east cow stopps
                dist[event[2]] = nCow.x - eCow.x;
                graph[event[1]].push_back(event[2]);
            } else{
                dist[event[1]] = eCow.y - nCow.y;
                graph[event[2]].push_back(event[1]);
            }
        }
    }
    //cout << 'h';
    //below code checks if stopped events actually happen
    for (int i = 0; i < n; i++){
        curAns = 0;
        fill(visited.begin(), visited.end(), 0);
        if (!visited[i]){
            dfs(i);
        }
        cout << curAns << '\n';
    }
    

}