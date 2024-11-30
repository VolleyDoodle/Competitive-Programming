#include <bits/stdc++.h>
using namespace std;
int n;
vector <bool> visited;
vector <int> shuffleCows;
int start, ans = 0;

/*
void dfs(int node){
    //node = 1, first case (sample)
    visited[shuffleCows[node]] = true;
    pastVisited[shuffleCows[node]] = true;
    if (pastVisited.count(shuffleCows[shuffleCows[node]])){
        ans+=eProc + 1;
        return;
        //good
    }
    if (!visited[shuffleCows[shuffleCows[node]]]){
        eProc++;
        dfs(shuffleCows[node]);
    }
}*/
void bfs(int node){
    vector <int> curVisited;
    queue <int> todo;
    int eProc = 0;
    bool cycleCheck = false;
    todo.push(node);
    while (!todo.empty()){
        eProc++;
        curVisited.push_back(todo.front());
        visited[todo.front()] = true;
        if (node == shuffleCows[todo.front()]){
            visited[todo.front()] = true;
            cycleCheck = true;
            break;
        }
        else if (!visited[shuffleCows[todo.front()]]){
            todo.push(shuffleCows[todo.front()]);
        }
        todo.pop();
    }
    if (cycleCheck) {ans+=eProc;}
    else {
        for (int e : curVisited){
            visited[e] = false;
        }
    }
    return;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    cin >> n;
    visited.resize(n + 1); 
    fill(visited.begin(), visited.end(), 0);
    shuffleCows.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> shuffleCows[i];
    }
    for (int i = 1; i <= n; i++){
        if (!visited[shuffleCows[i]]){
            bfs(i);
        }
    }
    cout << ans;

}