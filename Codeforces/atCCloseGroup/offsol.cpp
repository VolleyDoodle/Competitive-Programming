	#include <bits/stdc++.h>
using namespace std;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
	int n, m;
	cin >> n >> m;
	vector<int> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		// adjacency list represented as a bitmask
		adj[u] |= (1 << v);
		adj[v] |= (1 << u);
	}
    for (int i = 0; i < n; i++){
        adj[i] |= (1 << i);
    }
	vector<int> dp(1 << n, INT32_MAX);
	for (int mask = 0; mask < (1 << n); mask++) {
		bool connected = true;
		for (int u = 0; u < n; u++) {
			if (((mask >> u) & 1) != 0) {
				// check if u is connected to all other nodes in mask
				if (((adj[u]) & mask) != mask) {
					connected = false;
					break;
				}
			}
		}

		if (connected) { dp[mask] = 1; }
	}
    /*for (int i = 0; i < (1 << n); i++){
        if (dp[i] == INT32_MAX) continue;
        cout << "i: " << i << ": " << dp[i] << "\n";
    }*/
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int submask = mask; submask; submask = (submask - 1) & mask) {
			int subset = mask ^ submask;
			// submask has everything in mask but not in subset
			if (dp[subset] != INT32_MAX && dp[submask] != INT32_MAX) {
				dp[mask] = min(dp[mask], dp[subset] + dp[submask]);
			}
		}
	}

	cout << dp[(1 << n) - 1] << endl;
}