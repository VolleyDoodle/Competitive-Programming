#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> graphA, graphB;
//solution does not because of example
//7 6
//1 2 3 5 4 6
//1 2 3 6 4 5
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <int> a(k + 2), b(k + 2), count(n + 1, 0);
    for (int i = 1; i <= k; i++){
        cin >> a[i];
        count[a[i]]++;
    } 
    for (int i = 1; i <= k; i++){
        cin >> b[i];
        count[b[i]]++;
    } 
    
    a[0] = a[k]; a[k + 1] = a[1];
    b[0] = b[k]; b[k + 1] = b[1];
    graphA.resize(n + 1); graphB.resize(n + 1);
    for (int i = 1; i <= k; i++){
        graphA[a[i]].push_back(a[i - 1]); graphA[a[i]].push_back(a[i + 1]);
        graphB[b[i]].push_back(b[i - 1]); graphB[b[i]].push_back(b[i + 1]);
    }
    int isoAns = 0;
    int ans = 0; //basically just store largest component using neigbors of other ordering
    vector <bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++){
        if (count[i] == 0) {isoAns++;}
        if (visited[i] || count[i] != 2) continue;

        int tempAns = 0;

        queue <int> nodesToVisit;
        nodesToVisit.push(i);
        visited[i] = true;
        while (!nodesToVisit.empty()){
            tempAns++;
            int curParent = nodesToVisit.front();
            nodesToVisit.pop();
            //visited[curParent] = true;
            for (int& child : graphA[curParent]){
                if ((graphB[curParent][0] == child || graphB[curParent][1] == child) && !visited[child]){
                    visited[child] = true;
                    nodesToVisit.push(child);
                }
            }
            
        }
        ans = max(ans, tempAns);
    }

    /*for (int i = 1; i <= n; i++){
        if (count[i] == 0) ans++;
    }*/
    cout << ans + isoAns;

}