using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
int ans = 0;
int grid[101][101]; 
map <pair <int, int >, vector <pair <int, int>>> mGrid;
void recurse(pair <int, int> bLoc) {
	int bY = bLoc.first, bX = bLoc.second;
	
	if (mGrid.count(bLoc) > 0) {
		for (auto it : mGrid[bLoc]) {
			grid[it.first][it.second] = 1;
		}
	}
	if (grid[bY - 1][bX] == 1) { cout << "ran1"; recurse(pair <int, int>(bY - 1, bX)); }
	if (grid[bY + 1][bX] == 1) { cout << "ran2"; recurse(pair <int, int>(bY + 1, bX)); }
	if (grid[bY][bX + 1] == 1){ 
		cout << "ran3"; 
		recurse(pair <int, int>(bY, bX + 1)); }
	if (grid[bY][bX - 1] == 1) { cout << "ran4"; recurse(pair <int, int>(bY, bX - 1)); }
}
int main()
{
	ifstream fin("lightson.in");
	ofstream fout("lightson.out");
	grid[1][1] = 1;
	int n, m; fin >> n >> m;
	int x, y, a, b;

	for (int i = 0; i < m; i++) {
		fin >> x >> y >> a >> b;
		mGrid[make_pair(x, y)].push_back(make_pair(a,b));
	}
	recurse(pair <int, int>(1, 1));
	fout << ans;

}

