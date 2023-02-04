using namespace std;
#include <iostream>

int main()
{
	int t; cin >> t;
	long long n; long long ans_a, ans_b;
	for (int r = 0; r < t; r++) {
		cin >> n;
		ans_a = 1; ans_b = n - 1;
		for (int i = 1; i <= n / 2; i++) {
			long long a = i, b = n - i;
			if (b % a == 0) { 
				if (ans_a * ans_b > b) {
					ans_a = a; ans_b = b;
				}
			}
		}
		//cout << "ans: " << ans << endl;
		cout << ans_a << " " << ans_b << endl;
	}
}
