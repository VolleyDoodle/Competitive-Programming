using namespace std;

#include <iostream>
#include <unordered_map>
int main()
{
	int t; cin >> t;
	for (int r = 0; r < t; r++) {
		int n; cin >> n;
		string ans = "NO";
		unordered_map <string, int> m;
		string s; cin >> s;
		//cout << typeid(s[0]).name();
		for (int i = 0; i < n - 1; i++) {
			string temp = string(1,s[i]) + s[i + 1];
			if (m.count(temp) == 0) {
				m[temp] = i;
				continue;
			}
			if (m.count(temp) == 1 && m[temp] + 1 != i) {
				ans = "YES";
				m[temp] = i;
				break;
			}
			
		}
		cout << ans << endl;
	}
}