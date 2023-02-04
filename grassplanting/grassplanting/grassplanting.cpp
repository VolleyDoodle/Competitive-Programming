#include <fstream>
#include <iostream>
#include <map>
using namespace std;
int main()
{
	ifstream fin("planting.in");
	ofstream fout("planting.out");
	int n;
	int a, b;
	map <int, int> fields;
	fin >> n;
	for (int i = 0; i < n - 1; i++) {
		fin >> a >> b;
		if (fields.count(a) == 0) { fields[a] = 1; }
		if (fields.count(b) == 0) { fields[b] = 1; }
		if (fields.count(a) == 1) { fields[a]++; }
		if (fields.count(b) == 1) { fields[b]++; }
	}
	int ans = 1;
	for (auto i : fields) {
		ans = max(i.second, ans);
	}
	fout << ans;
}

