#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
	//ifstream cin("div7.in");
	//ofstream cout("div7.out");
	int n;
	cin >> n;
	int num;
	vector <long long> v;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> num; v.push_back(num + v[i]);
	}
	
	//for (int i = 0; i <= n; i++) { cout << v[i] << " "; }
	// << endl;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int x = i + 1; x <= n; x++) {
			//cout << "SUM: " << v[x] - v[i] << ": INDICES: " << x <<" " << i << endl;
			if ((v[x] - v[i]) % 7 == 0) { //success
				//cout << "ran ;)" << endl;
				ans = max(x - i, ans);
			}
		}
	}
	cout << ans;
}