#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
//wooww what a creative idea
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
    setIO("mootube");
    int n, q;
    cin >> n >> q;
    //input in p, q, r
    vector <vector <int>> rpq(n - 1, vector <int>(3));
    vector <vector <int>> queries(q, vector <int>(3));
    for (int i = 0; i < n - 1; i++){
        cin >> rpq[i][1] >> rpq[i][2] >> rpq[i][0]; 
    }
    //k (r), v
    for (int i = 0; i < q; i++){
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2] = i;
    }
    sort(rpq.begin(), rpq.end());
    reverse(rpq.begin(), rpq.end());
    sort(queries.begin(), queries.end());
    reverse(queries.begin(), queries.end());
    vector <int> ans(q);
    DisjointSets dsu(n + 1);
    int idx = 0;
    for (int i = 0; i < queries.size(); i++){
        while (idx < n - 1 && rpq[idx][0] >= queries[i][0]){
            dsu.unite(rpq[idx][1], rpq[idx][2]);
            idx++;
        }
        ans[queries[i][2]] = dsu.sizes[dsu.find(queries[i][1])] - 1;
    }
    for (int i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }
}