#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n;
    cin >> n;
    vector <vector <int>> graph(n + 1);
    vector <int> leaves, values(n + 1, 0);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //let the root == 1
    queue <pair <int, int>> q;
    q.push({1, 1});
    int curValE = 2, curValO = n * 2;
    while (!q.empty()){
        auto cur = q.front();
        q.pop();
        if (!cur.s){
            //if on even level
            values[cur.f] = curValE;
            curValE+=2;
        } else{
            values[cur.f] = curValO;
            curValO-=2;
        }
        bool leaf = true;
        for (int nxt : graph[cur.f]){
            if (!values[nxt]){
                leaf = false;
                q.push({nxt, (cur.s + 1)%2});
            }
        }
        if (leaf) leaves.push_back(cur.f);
    }
    for (int leaf : leaves){
        if (abs(values[graph[leaf][0]] - values[leaf]) == 2){
            values[leaf] = values[graph[leaf][0]] - 1;
        }
    }
    for (int i = 1; i < n + 1; i++){
        cout << values[i] << " ";
    }


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}