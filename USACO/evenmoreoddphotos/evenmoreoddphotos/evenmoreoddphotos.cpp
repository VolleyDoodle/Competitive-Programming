
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int n, temp;
	int ans = 0;
	cin >> n;
	int o = 0, e = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp % 2 == 0) { e++; }
		else { o++; }
	}
	while (true) {
		if (ans % 2 == 0) {
			if (e > 0) { e--; ans++; }
			else if (o > 1) { o -= 2; ans++; }
			else { ans--; break; }
		}
		else if (ans % 2 == 1) {
			if (o > 0) { o--; ans++; }
			else {
				e = 0;
			}
		}
		if (e == 0 && o == 0) {
			break;
		}
	}
	cout << ans;

}


