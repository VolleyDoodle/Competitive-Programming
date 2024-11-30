#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n + 1);
    set <pair <int, int>> S, D;
    for (int i = 0; i < m; i++){
        char s;
        int t1, t2;
        cin >> s >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
        if (s == 'S') {S.insert({t1, t2}); S.insert({t2, t1});}
        else {D.insert({t2, t1}); D.insert({t1, t2});}
    }

    vector <int> colorsOfNodes(n + 1, 0);
    int numOfComp = 0;
    bool impossible = false;
    for (int i = 1; i <= n; i++){
        if (colorsOfNodes[i] != 0) continue;
        numOfComp++;
        queue <int> nodesToVisit;
        colorsOfNodes[i] = 1;
        nodesToVisit.push(i);
        while (!nodesToVisit.empty()){
            int curParent = nodesToVisit.front();
            nodesToVisit.pop();

            for (int& child : graph[curParent]){
                if (colorsOfNodes[child] == 0){
                    nodesToVisit.push(child);
                    if (S.count({curParent, child})){
                        colorsOfNodes[child] = colorsOfNodes[curParent];
                        
                    } else{
                        colorsOfNodes[child] = colorsOfNodes[curParent] * -1;
                    }
                } else if (S.count({curParent, child})){
                    if (colorsOfNodes[curParent] != colorsOfNodes[child]) impossible = true;
                } else{
                    if (colorsOfNodes[curParent] == colorsOfNodes[child]) impossible = true;
                }
            }
        }
    }
    if (impossible){
        cout << 0;
    } else{
        cout << 1;
        for (int i = 0; i < numOfComp; i++) cout << 0;
    }
}