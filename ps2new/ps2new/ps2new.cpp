
// photoshoot_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	//ifstream cin("in.txt");
	//ofstream fout("outt.txt");
	int n, temp, loc = 0, ans = 0;
	int prev = 0;
	cin >> n;
	//fout << "n" << n << endl;
	int rht_most = n - 1;
	int a[5000], b[5000];
	for (int i = 0; i < n; i++) {
		cin >> temp; a[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		cin >> temp; b[i] = temp;
	}
	//logic
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < n; x++) {
			if (b[i] == a[x]) { 
				if (i == x) { break; }
				else {
					ans++;
					temp = a[x];
					for (int y = x; y > i; y--) {
						a[y] = a[y - 1];
					}
					a[i] = temp;
				}
			
			}
			
		}
	}
	cout << ans;
}



