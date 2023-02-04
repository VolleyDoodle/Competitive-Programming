#include <iostream>
#include <fstream>
using namespace std;
bool transLogic(int n, int fDice[], int sDice[]) {
	int greater = 0, lesser = 0;
	for (int i = 0; i < 4; i++) {
		for (int x = 0; x < 4; x++) {
			if (fDice[i] > sDice[x]) {
				greater++;
			}
			if (sDice[x] > fDice[i]) {
				lesser++;
			}
		}
	}
	return greater > lesser;
}
int main()
{
	int fDice[4], sDice[4], tDice[4];
	int n;
	string ans = "no";
	cin >> n;
	//non_trans when a beats b, b beats c, c beats a
	//or b beats a, c beats b, a beats c
	//
	for (int d = 0; d < n; d++) {
		for (int o = 0; o < 4; o++) { cin >> fDice[o]; }
		for (int p = 0; p < 4; p++) { cin >> sDice[p]; }
		//loop through all 10^4 cases
		for (int q = 1; q <= 10; q++) {
			tDice[0] = q;
			for (int w = 1; w <= 10; w++) {
				tDice[1] = w;
				for (int e = 1; e <= 10; e++) {
					tDice[2] = e;
					for (int r = 1; r <= 10; r++) {
						tDice[3] = r;
						if (transLogic(n, fDice, sDice) && transLogic(n, sDice, tDice) && transLogic(n, tDice, fDice)) {
							ans = "yes";
						}
						else if (transLogic(n, sDice, fDice) && transLogic(n, tDice, sDice) && transLogic(n, fDice, tDice)) {
							ans = "yes";
						}

						//logic LOL

					}
				}
			}
		}
		cout << ans << endl;
		ans = "no";
	}
}