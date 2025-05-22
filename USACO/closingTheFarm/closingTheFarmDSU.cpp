#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
class DisjointSets {
  public:
    vector<int> parents;
	vector<int> sizes;
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("closing");
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n + 1);
    vector <int> active(n + 1, 0), input(n);
    while (m--){
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    
    for (int i = 0; i < n; i++){
        cin >> input[n - i - 1];
    }
    //doProcess(input[n - 1], graph, active);
    DisjointSets dsu(n + 1);
    //active[input[n - 1]] = 1;
    int curComp = 0;
    vector <string> ans(n);
    for (int i = 0; i < n; i++){
        curComp++;
        active[input[i]] = 1;
        for (int nxtNode : graph[input[i]]){
            if (active[nxtNode] && dsu.unite(nxtNode, input[i])){
                curComp--;
            }
        }
        ans[n - i - 1] = (curComp == 1 ? "YES" : "NO");
    }
    for (string cAns : ans){
        cout << cAns << "\n";
    }
    
}