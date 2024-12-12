#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> tree;
vector <int> subTree, subTree2, balance;
vector <bool> visited;
multiset <int> potionM;
//11 out of 15 test cases
//issue is depth of nodes
void dfs(int curNode){
    visited[curNode] = true;
    bool leaf = true;
    for (int node : tree[curNode]){
        if (!visited[node]){
            leaf = false;
            dfs(node);
            //tree2[node].push_back(curNode);
            subTree[curNode] += subTree[node];
            //subTree2[curNode] += subTree2[node];
            //subTree[curNode]--;
        }
    }
    if (leaf){
        subTree[curNode] = 1;
    }
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> potions(n);
    subTree.resize(n + 1, 0);
    visited.resize(n + 1, false);
    tree.resize(n + 1);
    balance.resize(n + 1, 0);
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

    queue <int> roomsToVisit;
    set <int> roomsIn;

    fill(visited.begin(), visited.end(), false);
    for (int i = 1; i <= n; i++){
        if (tree[i].size() == 1 && i != 1){
            visited[i] = true;
            roomsToVisit.push(i);
        }
        
    }
    fill(visited.begin(), visited.end(), false);
    int ans = 0;
    
    while (!roomsToVisit.empty()){
        bool found = false;
        int curRoom = roomsToVisit.front();

        roomsToVisit.pop();
        auto it = potionM.find(curRoom);

        while (it != potionM.end() && subTree[curRoom] - balance[curRoom] > 0){
            balance[curRoom]++;
            ans++;
            potionM.erase(it);
            it = potionM.find(curRoom);
        }


        for (int nextRoom : tree[curRoom]){
            if (!visited[nextRoom] && ){
                visited[nextRoom] = true;
                roomsToVisit.push(nextRoom);
                
            }
            balance[nextRoom]+=balance[curRoom];
        }
    }
    
    cout << ans;

}