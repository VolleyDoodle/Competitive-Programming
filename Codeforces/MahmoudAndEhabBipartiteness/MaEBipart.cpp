#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> tree;
vector <int> colorsOfNodes;
long long red = 0, blue = 0;
void color(int curParent, int colorN){
    if (colorN > 0) red++;
    else blue++;
    colorsOfNodes[curParent] = colorN;

    for (int& child : tree[curParent]){
        if (colorsOfNodes[child] == 0){
            color(child, colorN * -1);
        }
    }
}
int main(){
    int n;
    cin >> n;
    tree.resize(n + 1);
    colorsOfNodes.resize(n + 1, 0);
    for (int i = 0; i < n - 1; i++){
        int t1, t2;
        cin >> t1 >> t2;
        tree[t1].push_back(t2);
        tree[t2].push_back(t1);
    }
    //color(1, 1);
    //bfs solution
    queue <pair <int, int>> nodesToVisit;
    nodesToVisit.push({1, 1});
    while (!nodesToVisit.empty()){

        pair <int, int> curParent = nodesToVisit.front();
        if (curParent.second == 1) red++;
        else blue++;
        colorsOfNodes[curParent.first] = curParent.second;
        nodesToVisit.pop();
        for (int& child : tree[curParent.first]){
            if (colorsOfNodes[child] == 0){
                nodesToVisit.push({child, curParent.second * -1});
            }
        }

    }
    cout << red * blue - (n - 1);

}