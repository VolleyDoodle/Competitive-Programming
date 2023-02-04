#include <iostream>
using namespace std;


string s;
int ans = 0;
bool vis[9][9];

void f(int i, int r, int c) {
	//int x = vis[r][c - 1] + vis[r][c + 1];
	//int y = vis[r - 1][c] + vis[r + 1][c];
	//if (x == 2 && y == 0 || x == 0 && y == 2)
		//return;
	if (!vis[r][c - 1] && !vis[r][c + 1] && vis[r + 1][c] && vis[r - 1][c]) { return; }
	if (vis[r][c - 1] && vis[r][c + 1] && !vis[r + 1][c] && !vis[r - 1][c]) { return; }
	if (i != 48 && r == 7 && c == 1) { return; }
	if (i == 48) {
		if (r == 7 && c == 1) {
			++ans;
		}

		return;
	}

	if (i == s.size())
		return;

	//vis[r][c] = 1;

	if (s[i] == 'U' || s[i] == '?') {
		if (!vis[r - 1][c]) {
			vis[r - 1][c] = true;
			f(i + 1, r - 1, c);
			vis[r - 1][c] = false;
		}
	}
		

	if (s[i] == 'D' || s[i] == '?') {
		if (!vis[r + 1][c]) {
			vis[r + 1][c] = true;
			f(i + 1, r + 1, c);
			vis[r + 1][c] = false;
		}
	}
		
			
	if (s[i] == 'R' || s[i] == '?') {
		if (!vis[r][c + 1]) {
			vis[r][c + 1] = true;
			f(i + 1, r, c + 1);
			vis[r][c + 1] = false;
		}
	}
		

	if (s[i] == 'L' || s[i] == '?') {
		if (!vis[r][c - 1]) {
			vis[r][c - 1] = true;
			f(i + 1, r, c - 1);
			vis[r][c - 1] = false;
		}
	}
		
			

	//vis[r][c] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; ++i)
		vis[0][i] = vis[i][0] = vis[8][i] = vis[i][8] = 1;
	vis[1][1] = true;


	cin >> s;
	f(0, 1, 1);
	cout << ans;
}
