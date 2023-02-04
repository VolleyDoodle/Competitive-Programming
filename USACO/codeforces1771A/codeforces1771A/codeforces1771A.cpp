// codeforces1771A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t; long long n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int minNum = INT_MAX, maxNum = -1, num;
		vector <int> nums;
		for (int x = 0; x < n; x++) {
			cin >> num; minNum = min(minNum, num); maxNum = max(maxNum, num); nums.push_back(num);
		}
		//cout << minNum << maxNum;

		long long countMin = 0, countMax = 0, ans = 0;
		if (maxNum == minNum) {
			long long none = n - 1;
			ans = none * n;
			cout << ans << endl;
		}
		else {
			for (int x = 0; x < n; x++) {
				if (nums[x] == minNum) { countMin++; }
				else if (nums[x] == maxNum) { countMax++; }
			}
			ans = 2 * countMin * countMax;
			cout << ans << endl;
		}
		
	}
}

