#include <bits/stdc++.h>
using namespace std;
const int bigNum = pow(10, 5) + 1;
int n, group;
string farms;
vector <vector <int>> tree(bigNum);
vector <int> groupId(bigNum);

void dfs(int parent, char cur){
    groupId[parent] = group;
    for (int node : tree[parent]){
        if (!groupId[node] && farms[node - 1] == cur){
            dfs(node, cur);
        }
    }
}
int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int m;
    cin >> n >> m >> farms;
    fill(groupId.begin(), groupId.end(), 0);
    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    //rooting doesnt matter
    group = 1;
    for (int i = 1; i <= n; i++){
        if (!groupId[i]){
            dfs(i, farms[i - 1]);
            group++;
        }
    }

    while (m--){
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (groupId[a] == groupId[b] && farms[a - 1] != c){
            cout << 0;
        } else{
            cout << 1;
        }
        
    }
}