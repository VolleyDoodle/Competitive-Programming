#include <iostream>
using namespace std;
int ans = 0;
bool squares[9][9]; //extra trues serve as walls instead of using if statement to check
void solve(string n, int i, int x, int y) {
	//cout << x << " " << y << endl;
	//cout << i << endl;
	//int tx = squares[y][x + 1] + squares[y][x - 1];
	//int ty = squares[y + 1][x] + squares[y - 1][x];
	//if ((tx == 2 && ty == 0) || (tx == 0 && ty == 2)) { return; }
	if (!squares[y][x + 1] && !squares[y][x - 1] && squares[y + 1][x] && squares[y - 1][x]) { return; }
	if (squares[y][x + 1] && squares[y][x - 1] && !squares[y + 1][x] && !squares[y - 1][x]) { return; }
	if (i != 48 && y == 7 && x == 1) { return; }
	if (i == 48) {
		if (y == 7 && x == 1) { ans++; }
		else { return; }


	}
	else {
		if ((n[i] == '?' || n[i] == 'U') && !squares[y - 1][x]) {
			squares[y - 1][x] = true;
			solve(n,i + 1, x, y - 1);
			squares[y - 1][x] = false;
		}
		if ((n[i] == '?' || n[i] == 'D') && !squares[y + 1][x]) {
			//cout << 'D' << endl;
			squares[y + 1][x] = true;
			solve(n,i + 1, x, y + 1);
			squares[y + 1][x] = false;
		}
		if ((n[i] == '?' || n[i] == 'R') && !squares[y][x + 1]) {
			//cout << 'R' << endl;
			squares[y][x + 1] = true;
			solve(n,i + 1, x + 1, y);
			squares[y][x + 1] = false;
		}
		if ((n[i] == '?' || n[i] == 'L') && !squares[y][x - 1]) {
			squares[y][x - 1] = true;
			solve(n, i + 1, x - 1, y);
			squares[y][x - 1] = false;
		}
	}


}
int main()
{
	string n;
	for (int i = 1; i < 8; i++) {
		for (int x = 1; x < 8; x++) {
			squares[i][x] = false;
		}
	}
	for (int i = 0; i < 9; i++) { squares[0][i] = squares[8][i] = true; }
	for (int i = 0; i < 9; i++) { squares[i][0] = squares[i][8] = true; }
	squares[1][1] = true;
	cin >> n;
	//cout << n.size();
	solve(n, 0, 1, 1);
	cout << ans;

}

