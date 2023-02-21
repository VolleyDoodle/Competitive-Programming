#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <vector <int>> graph;
vector <bool> visitedF, visitedS;
int minField, maxField;
void dfsMin(int node){
    visitedF[node] = true;
    if (visitedF[node] && visitedS[node]){
        minField = -1;
    }
    for (int curNode: graph[node]){
        if (!visitedF[curNode]){
            minField = min(minField, curNode);
            dfsMin(curNode);
        }
    }
}
void dfsMax(int node){
    visitedS[node] = true;
    for (int curNode: graph[node]){
        if (!visitedS[curNode]){
            maxField = max(maxField, curNode);
            dfsMax(curNode);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        graph.clear(); visitedF.clear(); visitedS.clear();
        maxField = 1;
        cin >> n >> m;
        minField = n;
        graph.resize(n + 1); visitedF.resize(n + 1); visitedS.resize(n + 1);
        for (int i = 0; i < m; i++){
            int t, tt; cin >> t >> tt;
            graph[t].push_back(tt); graph[tt].push_back(t);
        }
        dfsMax(1);
        dfsMin(n);
        int mid = (maxField + minField)/2;
        //cout << "maxField: " << maxField << "\n" << "minField: " << minField << "\n";
        if (minField == -1){cout << 0 << "\n";}
        else {cout << fixed << setprecision(0) << pow(mid - maxField, 2) + pow(minField - mid, 2)<< "\n";}
    }
}