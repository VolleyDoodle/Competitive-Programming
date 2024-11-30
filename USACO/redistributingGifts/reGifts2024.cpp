#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> graph;
int main(){

    //basically problem is worded really badly
    //each answer is INDEPENDENT from each other
    //so just the best answer cow i can get
    //problem pretty easy otherwise
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <vector <int>> prefVec(n + 1, vector <int>(n + 1));
    graph.resize(n + 1);
    for (int i = 1; i <= n; i++){
        for (int x = 0; x < n; x++){
            int t1;
            cin >> t1;
            prefVec[i][t1] = x;
        }
    }
    for (int i = 1; i <= n; i++){

        for (int x = 1; x <= n; x++){
            if (prefVec[x][i] < prefVec[x][x]){
                graph[i].push_back(x);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        int curAns = i;
        vector <bool> visited(n + 1, false);

        queue <int> nodesToVisit;
        nodesToVisit.push(curAns);

        while (!nodesToVisit.empty()){
            
            int parent = nodesToVisit.front();
            visited[parent] = true;
            nodesToVisit.pop();
            if (prefVec[i][curAns] > prefVec[i][parent]){
                curAns = parent;
            }
            for (int& child: graph[parent]){
                if (!visited[child]){
                    nodesToVisit.push(child);
                }
            }
        } 
        cout << curAns << "\n";
    }

}