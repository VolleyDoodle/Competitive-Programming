// photoshoot_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int n, temp, loc = 0, ans = 0;
	fin >> n;
	fout << "n" << n << endl;
	int lft_most = n - 1;
	int a[5000], b[5000];
	for (int i = 0; i < n; i++) {
		fin >> temp; a[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		fin >> temp; b[i] = temp;
	}
	//logic
	while (lft_most != 0) {
		for (int i = 0; i < n; i++) {
			if (b[i] == a[lft_most]) { loc = i; }
		}
		fout << "loc " << loc << endl;
		fout << "left " << lft_most << endl;
		if (loc == lft_most) { lft_most--; }
		
		else {
			ans++;
			temp = a[lft_most];
			for (int i = lft_most; i > loc; i--) {
				a[i] = a[i - 1];
			}
			a[loc] = temp;
		}
		for (int i = 0; i < n; i++) { fout << a[i] << " "; }
		fout << endl;
		for (int i = 0; i < n; i++) { fout << b[i] << " "; }
		fout << endl;	
	}
	fout << ans;
}

