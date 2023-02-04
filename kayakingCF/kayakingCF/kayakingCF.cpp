#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n;
int solve(int i, int x, vector <int> weights) {
	//cout << "items erased: " << weights[i] << " " << weights[x] << endl;
	weights.erase(weights.begin() + i);
	weights.erase(weights.begin() + x);
	sort(weights.begin(), weights.end());
	int rValue = 0;
	for (int y = 0; y < (2 * n) - 2; y+=2) {
		rValue += weights[y + 1] - weights[y];
	}
	//cout << "value: " << rValue << endl;
	//cout << endl;
	return rValue;
}
int main()
{
	
	cin >> n;
	int ans = INT_MAX;
	vector <int> weights;
	for (int r = 0; r < 2 * n; r++) {
		int num;
		cin >> num;
		weights.push_back(num);
	}

	for (int x = 0; x < (2 * n) - 1; x++) {
		
		for (int i = x + 1; i < 2 * n; i++) {
			ans = min(ans, solve(i, x, weights));
		}

	}
	cout << ans;
}

