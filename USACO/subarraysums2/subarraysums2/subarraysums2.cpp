#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
	long long n, x;
	long long ans = 0;
	cin >> n >> x;
	vector <long long> pfs(n);
	pfs.push_back(0);
	for (int i = 1; i <= n; i++) {
		long long num; cin >> num;
		pfs[i] = num + pfs[i - 1];
	}

	map <long long, int> m;
	m[0] = 1;
	for (int i = 1; i <= n; i++) {

		if (m.count(pfs[i] - x) > 0) {
			ans += m[pfs[i] - x];
		}
		if (m.count(pfs[i]) > 0) {
			m[pfs[i]]++;
		}
		else {
			m[pfs[i]] = 1;
		}

	}
	cout << ans;
}



