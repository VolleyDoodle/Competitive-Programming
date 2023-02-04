#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
unordered_map <int, vector <int>> roads;
string dataId;
int ai, bi; char ci;
int ans = 0;
void solve(int cFarm, int pAns) {
	if (pAns == 1 && cFarm == bi) { 
		ans = 1; return; 
	} //end statement for recursion
	if (roads[cFarm].size() == 0) { return; }
	for (auto element : roads[cFarm]) {
		if (dataId[element - 1] == ci) { 
			solve(element, 1); 
		}
		solve(element, pAns);
	}

}
int main()
{
	ifstream fin("milkvisits.in");
	ofstream fout("milkvisits.out");
	int n, m;
	fin >> n >> m;
	fin >> dataId;

	for (int i = 0; i < n - 1; i++) {
		int X, Y; fin >> X >> Y;
		roads[X].push_back(Y); roads[Y].push_back(X);
	}
	for (int i = 0; i < m; i++) {
		fin >> ai >> bi >> ci;
		solve(ai, 0);
		fout << ans; ans = 0;
	}

}
