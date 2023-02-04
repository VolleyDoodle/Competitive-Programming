// reststops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int xc[100001][2];
int main()
{
	int l, n, rf, rb;
	ifstream fin("reststops.in");
	ofstream fout("reststops.out");
	fin >> l >> n >> rf >> rb;
	for (int i = 0; i < n; i++) {
		fin >> xc[i][0] >> xc[i][1];
	}
	//bubble sort
	for (int i = 0; i < n; i++){

	}


}
