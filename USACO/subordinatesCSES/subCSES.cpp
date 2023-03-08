#include <bits/stdc++.h>
using namespace std;
const int SZ = 2e5 + 1;
vector <int> tree[SZ];
vector <int> subTree(SZ);
void dfs(int node){
    for (int curNode : tree[node]){
        //subTree[node]++;
        dfs(curNode);
        subTree[node]+=subTree[curNode];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    fill(subTree.begin(), subTree.end(), 1);
    //above code or commented code in dfs works
    for (int i = 2; i <= n; i++){
        int t; cin >> t;
        tree[t].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++){
        cout << subTree[i] - 1 << ' ';
    }
}