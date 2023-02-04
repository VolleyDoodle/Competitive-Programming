
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, x, num;
	ifstream fin("input.in");
	ofstream fout("output.out");
	fin >> n >> x;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		fin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	while (i < j) {

		if (v[i] + v[j] > x) { j--; }
		if (v[i] + v[j] < x) { i++; }
		if (v[i] + v[j] == x) { fout << i << " " << j; break; }
	}
}

