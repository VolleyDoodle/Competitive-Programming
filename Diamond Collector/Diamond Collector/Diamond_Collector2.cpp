// Diamond Collector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int absValue(int n) {
	if (n < 0) {
		return n * -1;
	}
}
int main()
{
	int n, k;
	int rocks[1000];
	int tempAns = 0, ans = 0;
	ifstream fin("diamond.in");
	ofstream fout("diamond.out");
	fin >> n >> k;
	for (int i = 0; i < n; i++) {
		fin >> rocks[i];
	}
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < n; c++) {
			if (i != c && absValue(rocks[i] - rocks[c]) <= k) {
				//fout << absValue(rocks[i] - rocks[c]) << " ";
				//fout << rocks[i] << " " << rocks[c] << endl;
				tempAns++;
			}
		}
		if (tempAns > ans) {
			ans = tempAns;
		}
		tempAns = 0;

	}
	fout << ans;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
