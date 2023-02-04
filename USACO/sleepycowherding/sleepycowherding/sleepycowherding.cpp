
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
	int a[3];
	ifstream fin("herding.in");
	ofstream fout("herding.out");
	fin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	//find min
	if (a[0] + 1 == a[1] && a[1] + 1 == a[2]) { fout << "0\n"; }
	else if (a[2] - a[1] == 2) { fout << "1\n"; }
	else { fout << "2\n"; }
	//find max
	fout << max(a[1] - a[0], a[2] - a[1]) - 1;


}


