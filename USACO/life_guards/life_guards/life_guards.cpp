
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");
	bool a[1001];
	for (int i = 0; i < 1001; i++) { a[i] = false; }
	int b[101][2];
	int n, temp_ans = 0, ans = 0;
	fin >> n;
	for (int x = 0; x < n; x++) {
		fin >> b[x][0] >> b[x][1];
		for (int i = b[x][0] + 1; i <= b[x][1]; i++) { a[i] = true; }
	}
	for (int x = 0; x < n; x++) {
		for (int i = b[x][0] + 1; i <= b[x][1]; i++) { a[i] = false; }
		for (int y = 0; y < n; y++) {
			for (int i = b[y][0] + 1; i <= b[y][1]; i++) { 
				if (y != x){ a[i] = true; }			
			}
		}
		for (int i = 0; i < 1000; i++) {
			if (a[i] == true) { temp_ans++; }
		}
		for (int i = b[x][0] + 1; i <= b[x][1]; i++) { a[i] = true; }
		ans = max(ans, temp_ans);
		temp_ans = 0;
	}
	fout << ans;

}

