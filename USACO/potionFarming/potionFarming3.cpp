#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> tree;
vector <int> subTree, balance, depth;
vector <bool> visited;
multiset <int> potionM;
//15 out of 15 test cases
void dfs(int curNode){
    visited[curNode] = true;
    bool leaf = true;
    for (int node : tree[curNode]){
        if (!visited[node]){
            leaf = false;
            depth[node]+=depth[curNode];
            dfs(node);
            subTree[curNode] += subTree[node];
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
    depth.resize(n + 1, 1);
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

    priority_queue <pair <int, int>, vector <pair <int, int>>> roomsToVisit;
    set <int> roomsIn;

    fill(visited.begin(), visited.end(), false);
    for (int i = 1; i <= n; i++){
        if (tree[i].size() == 1 && i != 1){
            visited[i] = true;
            roomsToVisit.push({depth[i], i});
        }
        
    }
    fill(visited.begin(), visited.end(), false);
    int ans = 0;
    //essentially a bfs, but starting from leaves
    //pushing nodes in by depth using priority_queue
    //really nice solution tho 
    while (!roomsToVisit.empty()){
        bool found = false;
        pair <int, int> curRoom = roomsToVisit.top();

        roomsToVisit.pop();
        auto it = potionM.find(curRoom.second);

        while (it != potionM.end() && subTree[curRoom.second] - balance[curRoom.second] > 0){
            balance[curRoom.second]++;
            ans++;
            potionM.erase(it);
            it = potionM.find(curRoom.second);
        }


        for (int nextRoom : tree[curRoom.second]){
            if (!visited[nextRoom]){
                visited[nextRoom] = true;
                roomsToVisit.push({depth[nextRoom], nextRoom});
                
            }
            balance[nextRoom]+=balance[curRoom.second];
        }
    }
    
    cout << ans;

}