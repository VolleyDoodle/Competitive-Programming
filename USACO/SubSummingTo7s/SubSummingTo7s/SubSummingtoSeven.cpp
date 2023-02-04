#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream fin("div7.in");
	ofstream fout("div7.out");
	int n;
	fin >> n;
	int num;
	vector <long long> v;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		fin >> num; v.push_back(num + v[i]);
	}
	for (int i = 0; i <= n; i++) { fout << v[i] << " "; }
	for (int i = 1; i < n; i++) {
		for (int x = i + 1; x <= n; x++) {

		}
	}
}