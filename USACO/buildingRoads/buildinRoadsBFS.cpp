#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> roads;
vector <bool> visited;
queue <int> todo;
void bfs(int node){
    visited[node] = true;
    todo.push(node);
    while (!todo.empty()){
        for (int curNode : roads[todo.front()]){
            if (!visited[curNode]){
                todo.push(curNode);
                visited[curNode] = true;
            }
        }
        todo.pop();
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    roads.resize(n + 1); visited.resize(n + 1, 0);
    for (int i = 0; i < m; i++){
        int tc1, tc2;
        cin >> tc1 >> tc2;
        roads[tc1].push_back(tc2);
        roads[tc2].push_back(tc1);
    }
    int c1 = -1;
    vector <int> ans;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            if (c1 == -1){c1 = i;}
            else{
                ans.push_back(i);
            }
            bfs(i);
        }
    }
    cout << ans.size() << "\n";
    for (int element : ans){
        cout << c1 << " " << element << "\n";
    }
}