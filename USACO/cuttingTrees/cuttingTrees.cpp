#include <bits/stdc++.h>
using namespace std;
const int bigNum = 1 + pow(10, 5);
vector <vector <int>> tree;
vector <int> subTree(bigNum);
vector <bool> visited(bigNum);
int n, k, mid, curCount;
void dfs(int vertex){
    visited[vertex] = true;
    for (int child : tree[vertex]){
        if (!visited[child]){
            dfs(child);
            subTree[vertex]+=subTree[child];
        } 
    }
    if (subTree[vertex] >= mid){ //good, cut off subtree
        curCount++;
        subTree[vertex] = 0;
    } 
    if (curCount >= k + 1){
        return;
    }

}
void solve(){
    cin >> n >> k;
    tree.clear();
    tree.resize(n + 1);
    for (int i = 0; i < n - 1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }
    //binary search answer !!
    
    int low = 1, high = n / (k + 1), ans = -1;
    while (high >= low){
        curCount = 0;
        fill(subTree.begin(), subTree.end(), 1);
        fill(visited.begin(), visited.end(), 0);
        mid = low + (high - low)/2;
        dfs(1);
        if (curCount >= k + 1){
            low = mid + 1;
            ans = max(ans, mid);
        } else{
            high = mid - 1;
        }
    }
    cout << ans << "\n" ;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}