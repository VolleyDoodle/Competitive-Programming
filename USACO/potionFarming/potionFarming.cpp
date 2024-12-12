#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> tree, tree2;
vector <int> subTree, subTree2;
vector <bool> visited;
multiset <int> potionM;
int ans = 0, curRoom = -1;
//8 out of 15 test cases
//just too slow O(n^2)
void dfs2(int curNode){
    
    visited[curNode] = true;
    auto it = potionM.find(curNode);
    if (curRoom == -1 && it != potionM.end()){
        potionM.erase(it);
        ans++;
        //visited[curNode] = true;
        curRoom = curNode;
    }
    if (curNode == 1) return;
    for (int node : tree2[curNode]){
        /*if (subTree2[node] >= subTree2[curNode]){
            dfs2(node);
        }*/
       dfs2(node);
    }
}
void dfs(int curNode){
    visited[curNode] = true;
    bool leaf = true;
    for (int node : tree[curNode]){
        if (!visited[node]){
            leaf = false;
            dfs(node);
            tree2[node].push_back(curNode);
            subTree[curNode] += subTree[node];
            subTree2[curNode] += subTree2[node];
            //subTree[curNode]--;
        }
    }
    if (leaf){
        subTree[curNode] = 1;
    }
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> potions(n);

    subTree.resize(n + 1, 0);
    subTree2.resize(n + 1, 1);
    visited.resize(n + 1, false);
    tree.resize(n + 1);
    tree2.resize(n + 1);

    for (int i = 0; i < n; i++){
        cin >> potions[i];
    }
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);

    for (int i = 0; i < subTree[1]; i++){
        potionM.insert(potions[i]);
    }
    fill(visited.begin(), visited.end(), false);
    vector <int> leaves;
    for (int i = 1; i <= n; i++){
        if (tree[i].size() == 1 && i!=1){
            leaves.push_back(i);
        }
    }
    for (int i = 0; i < leaves.size(); i++){
        curRoom = -1;
        dfs2(leaves[i]);
    }
    cout << ans;


}