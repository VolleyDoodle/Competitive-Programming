	#include <bits/stdc++.h>
using namespace std;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
int main() {
    setIO("txt");
	int pool_size;
	int team_size;
	int aud_size;
	cin >> pool_size >> team_size >> aud_size;
	vector<pair<int, int>> aud_contrib(pool_size);
	for (int i = 0; i < pool_size; i++) {
		cin >> aud_contrib[i].first;
		aud_contrib[i].second = i;
	}
	sort(aud_contrib.begin(), aud_contrib.end(), greater<pair<int, int>>());

	vector<vector<int>> raw_team_contrib(pool_size, vector<int>(team_size));
	for (int i = 0; i < pool_size; i++) {
		for (int j = 0; j < team_size; j++) { cin >> raw_team_contrib[i][j]; }
	}
	vector<vector<int>> team_contrib(pool_size, vector<int>(team_size));
	for (int i = 0; i < pool_size; i++) {
		team_contrib[i] = raw_team_contrib[aud_contrib[i].second];
	}

	vector<vector<long long>> max_strength(pool_size + 1,
	                                       vector<long long>(1 << team_size, -1));
	max_strength[0][0] = 0;
	for (int up_to = 1; up_to <= pool_size; up_to++) {
		max_strength[up_to] = max_strength[up_to - 1];
		for (int subset = 0; subset < (1 << team_size); subset++) {
			int curr_aud = up_to - __builtin_popcount(subset) - 1;
			if (curr_aud < aud_size && max_strength[up_to - 1][subset] != -1) {
				max_strength[up_to][subset] = max(max_strength[up_to][subset], max_strength[up_to - 1][subset] + aud_contrib[up_to - 1].first);
			}

			for (int t = 0; t < team_size; t++) {
				int prev = subset & ~(1 << t);
				if (!(subset & (1 << t)) || max_strength[up_to - 1][prev] == -1) {
					continue;
				}
				max_strength[up_to][subset] =max (max_strength[up_to][subset], max_strength[up_to - 1][prev] + team_contrib[up_to - 1][t]);
			}
		}
	}
	cout << max_strength[pool_size][(1 << team_size) - 1] << endl;
}