
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
	int n, k, b;
	ifstream fin("maxcross.in");
	ofstream fout("maxcross.out");
	fin >> n >> k >> b;
	vector <int> pfs(n);
	vector <int> repair;
	pfs.push_back(0);
	while (b--) {
		int t; fin >> t;
		repair.push_back(t);
	}
	sort(repair.begin(), repair.end());
	int x = 0;
	for (int i = 1; i <= n; i++) {
		if (i != repair[x]) {
			pfs[i] = pfs[i - 1] + 1;
		}
		else {
			pfs[i] = pfs[i -1];
			x++;
		}
	}
	int ans = INT_MIN;

	for (int i = 1; i <= n - k; i++) {
		ans = max(ans, pfs[i + k] - pfs[i]);
	}
	fout << k - ans;

	


}

