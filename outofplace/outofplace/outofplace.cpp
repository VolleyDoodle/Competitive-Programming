
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n;
ifstream fin("outofplace.in");
ofstream fout("outofplace.out");
int main()
{

	fin >> n;
	int ans = 0;
	int a[101];
	int b[101];
	for (int i = 0; i < n; i++) {
		fin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		if (b[i] != a[i]) { ans++; }
	}
	ans--;
	if (ans < 0) { ans = 0; }
	fout << ans;
	
	

}

