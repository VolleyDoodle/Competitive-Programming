#include <bits/stdc++.h>
using namespace std;
int n, p, curLen;
vector <vector <int>> astros;
vector <bool> visited;
vector <int> countC;
void dfs(int curNode){
    for (int conNode : astros[curNode]){
        if (!visited[conNode]){
            curLen++;
            visited[conNode] = true;
            dfs(conNode);
        }
    }
}
int main(){
    
    cin >> n >> p;
    visited.resize(n); astros.resize(n);
    fill(visited.begin(), visited.end(), 0);
    while (p--){
        int ar1, ar2;
        cin >> ar1 >> ar2;
        astros[ar1].push_back(ar2);
        astros[ar2].push_back(ar1);
    }
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            visited[i] = 1;
            curLen = 1;
            dfs(i);
            countC.push_back(curLen);
        }
    }
    int ans = 0;
    for (int i = 0; i < countC.size() - 1; i++){
        for (int j = i + 1; j < countC.size(); j++){
            ans+=countC[i] * countC[j];
        }
    }
    cout << ans;

}