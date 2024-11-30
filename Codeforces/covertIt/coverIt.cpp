#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n + 1);
    vector <int> colorsOfNodes(n + 1, 0);
    for (int i = 0; i < m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }
    vector <int> c1, c2;
    queue <pair <int, int>> nodesToVisit;
    colorsOfNodes[1] = 1;
    nodesToVisit.push({1, 1});
    while (!nodesToVisit.empty()){
        pair <int, int> curParent = nodesToVisit.front();
        nodesToVisit.pop();

        if (curParent.second == 1) c1.push_back(curParent.first);
        else c2.push_back(curParent.first);
        

        for (int& child : graph[curParent.first]){
            if (colorsOfNodes[child] == 0){
                colorsOfNodes[child] = curParent.second * -1;
                nodesToVisit.push({child, curParent.second * -1});
            }
        }
    }
    if (c1.size() <= n/2){
        cout << c1.size() << "\n";
        for (int& i : c1) cout << i << " ";
    } else{
        cout << c2.size() << "\n";
        for (int& i : c2) cout << i << " ";
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}