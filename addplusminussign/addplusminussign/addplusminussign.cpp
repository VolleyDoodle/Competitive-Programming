#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	int t, n;
	string str;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> str;
		int cur = 0;
		for (int i = 1; i < n; i++) {
			if (str[i] == '0') { cout << "+"; }
			else if (str[i] == '1' && cur >= 0) { cur--; cout << "-"; }
			else { cur++; cout << "+"; }
		}
		cout << endl;
	}
}

