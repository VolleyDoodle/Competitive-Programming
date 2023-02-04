
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<char> v(n);
	int gCount = 0, hCount = 0, ans = 0;
	char temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.at(i) = temp;
	}
	for (int i = 0; i < n; i++) {
		for (int x = i; x < n; x++) {
			if (v[x] == 'G') { gCount++; }
			if (v[x] == 'H') { hCount++; }
			if (x - i >= 2) {
				if (gCount == 1 || hCount == 1) {
					ans++;
				}
			}
		}
		gCount = 0, hCount = 0;
		
	}
	cout << ans;
}

