#include <bits/stdc++.h>
using namespace std;
void dfs(vector <set <int>>& graph, vector <int>& ids, int curNode, int ccId, vector <int>& nCount){
    ids[curNode] = ccId;
    if (graph[curNode].size() == 1){
        nCount[ccId]++;
    }
    for (int nextNode : graph[curNode]){
        if (ids[nextNode] == -1){
            dfs(graph, ids, nextNode, ccId, nCount);
        }
    }
}
void solve(){
    int n;
    cin >> n;
    vector <set <int>> graph(n + 1);
    vector <int> ids(n + 1, -1), nCount;
    for (int i = 1; i <= n; i++){
        int tt;
        cin >> tt;
        graph[tt].insert(i);
        graph[i].insert(tt);
    }
    int ccId = 0;
    for (int i = 1; i <= n; i++){
        if (ids[i] == -1){
            nCount.push_back(0);
            dfs(graph, ids, i, ccId, nCount);
            ccId++;
        }
    }
    //cout << "h";
    //each cc is either just a cycle
    //or it is a straight line
    //all lines can be added together (add ends after)
    //cycles are stuck like that 
    int bambooCnt = 0, cycleCount = 0;
    for (int ccCount : nCount){
        if (ccCount == 0) cycleCount++;
        else bambooCnt++;
    }
    cout << cycleCount + min(bambooCnt, 1) << " " << cycleCount + bambooCnt;

}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}