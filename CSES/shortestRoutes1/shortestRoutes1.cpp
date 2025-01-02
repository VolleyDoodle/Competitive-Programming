#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
//literally just dijkstra or bellman ford
vector <int> bellmanFord(vector <vector <pair <int, int>>>& graph){
    //bellman ford basically says
    //the shortest path will always go through <= n - 1 nodes
    //why? because the first run, will find shortest path from start to all nodes 1 edge away
    //second run, will find shortest path from node to all nodes 2 edge away
    
}
vector <int> dijkstra(vector <vector <pair <int, int>>>& graph){

    
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, int>>> graph(n + 1);
    
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    //graph is {id, weight}
    //pq is {weight, id}
    //can use bellman ford or dijikstra
    vector <int> shortest = bellmanFord(graph);

}