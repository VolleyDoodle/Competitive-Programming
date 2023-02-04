// longestStrickCF.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int u = 0; u < t; u++) {
		int n, k;
		cin >> n >> k;
		vector <int> nums;
		//set <int> nums;
		map <int, int> amtNums;
		for (int x = 0; x < n; x++) {
			int num;
			cin >> num;
			//nums.insert(num);
			nums.push_back(num);
			if (amtNums.count(num) == 0) {
				amtNums[num] = 1;
			}
			else {
				amtNums[num]++;
			}
		}
		sort(nums.begin(), nums.end());
		int l = -2, r = -1;
		bool check = false;
		int curNum = -4, curStart = -1, count = 0, number;
		for (int i = 0; i < n; i++) {
			number = nums[i];
			count++;
			if (amtNums[number] >= k) {
				if (number != curNum + 1 && number != curNum) {
					check = false;
					if (l - r <= curNum - curStart) {
						l = curNum; r = curStart;
					}
				}
				//cout << "ran bit";
				curNum = number;
				if (!check) {
					check = true;
					curStart = number;
				}
				if (count == nums.size()) {
					if (l - r < curNum - curStart) {
						l = curNum; r = curStart;
						check = false;
					}
				}
			}
			else {
				check = false;
				if (l - r <= curNum - curStart) {
					l = curNum; r = curStart;
					
				}
			}
		}
		if (l == -2 && r == -1) {
			cout << "-1" << endl;
		}
		else {
			cout << r << " " << l << endl;
		}
		
	}
}

