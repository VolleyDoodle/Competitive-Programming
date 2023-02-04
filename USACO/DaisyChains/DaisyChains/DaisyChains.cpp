// DaisyChains.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int averageFind(float k, float m, float flowers[]) {
	float sum = 0;
	//cout << "KM " << k << " " << m << endl;
	for (int i = k; i <= m; i++) {
		sum += flowers[i];
	}
	//cout << "bSUm " << sum << endl;
	sum = sum / (m - k + 1);
	//cout << "Average " << sum << endl;
	for (int i = k; i <= m; i++) {
		if (flowers[i] == sum) {
			return 1;
		}
	}
	return 0;

}
int main()
{
	int n;
	int ans = 0;
	cin >> n;
	//cout << "n " << n << endl;
	float flowers[100];
	for (int i = 0; i < n; i++) {
		cin >> flowers[i];
		//cout << "flowers[i] " << flowers[i] << endl;
	}
	for (float i = 0; i < n - 1; i++) {
		for (float c = i + 1; c < n; c++) {
			ans+=averageFind(i, c, flowers);
			//cout << "Answers " << averageFind(i, c, flowers) << " " << ans << endl;
		}
	}
	cout << ans + n;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

