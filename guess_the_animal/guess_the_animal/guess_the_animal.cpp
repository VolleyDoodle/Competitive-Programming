
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
	ifstream fin("guess.in");
	ofstream fout("guess.out");
	int n, amt, temp_ans = 1, ans = 1;
	string temp, s;
	fin >> n;
	vector<string> arr[101];
	for (int i = 0; i < n; i++) {
		fin >> temp;
		arr[i].push_back(temp);
		fin >> amt;
		for (int x = 0; x < amt; x++) { fin >> temp;  arr[i].push_back(temp); }
	}
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < n; x++) {
			if (i != x) {
				for (int y = 1; y < arr[i].size(); y++) {
					for (int w = 1; w < arr[x].size(); w++) {
						if (arr[i][y] == arr[x][w]) { temp_ans++; }
					}
				}
				ans = max(ans, temp_ans);
				temp_ans = 1;
			}
		}
	}
	fout << ans;

}