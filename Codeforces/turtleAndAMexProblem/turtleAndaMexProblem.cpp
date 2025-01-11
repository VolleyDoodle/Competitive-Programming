#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n, m;
    cin >> n >> m;
    map <int, vector <int>> graph;
    int start = 0;
    long long biggestVis = 0;
    for (int i = 0; i < n; i++){
        int l;
        cin >> l;
        vector <long long> a(l);
        for (int x = 0; x < l; x++){
            cin >> a[x];
        }
        a.push_back(-1); a.push_back(l + 4);
        sort(a.begin(), a.end());
        int cnt = 0;
        //vector <int> mex(2);
        for (int x = 0; x < l + 5; x++){
            if (a[x] + 1 != a[x + 1] && a[x] != a[x + 1]){
                //mex[cnt] = a[x] + 1;
                biggestVis = max(biggestVis, a[x] + 1);
                cnt++;
                a.insert(a.begin() + x + 1, a[x] + 1);
            }
            if (cnt == 2 || x == a.size() - 1) break;
        }
        /*graph[mex[0]].push_back(mex[1]);
        graph[mex[1]].push_back(mex[0]);
        start = mex[0];*/
    }
    /*map <int, bool> visited;
    long long biggestVis = start;
    for (auto& e : graph){
        int i = e.first;
        if (!visited[i] && !graph[i].empty()){
            visited[i] = true;
            queue <int> nodes;
            nodes.push(i);
            while (!nodes.empty()){
                int cur = nodes.front();
                nodes.pop();
                biggestVis = max(biggestVis, (long long)cur);
                for (int node : graph[cur]){
                    if (!visited[node]){
                        visited[node] = true;
                        nodes.push(node);
                    }
                }
            }
        }
    }*/
    
    long long ans = (min(biggestVis, m) + 1) * (biggestVis);
    if (m > biggestVis){
        long long st = m - biggestVis;
        ans+= (m + biggestVis + 1) * (st)/2;
    }
    cout << ans;

}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}