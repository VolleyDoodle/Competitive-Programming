

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
	int t; cin >> t;
	while (t--) {
		int a; cin >> a;
		long long ans = 0;
		string s; cin >> s;
		vector <long long> pfs(a + 1);
		for (int i = 1; i <= a; i++) {
			pfs[i] = (s[i - 1] - '0') + pfs[i - 1];
		}
		int right = 0; int left = 1;
		map <long long, long long> m;
		
		m[0] = 1;
		
		
		for (int i = 1; i <= a; i++) {
			if (m.count(pfs[i] - i) > 0) {
				ans += m[pfs[i] - i];
			}
			m[pfs[i] - i]++;
		}
		cout << ans << endl;
		
	}
	
}
