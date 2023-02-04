
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	//ifstream cin("input.in");
	//ofstream cout("output.out");
	int n, q, num;
	int l, r; //(inputs)
	cin >> n >> q;
	vector <int> v;
	vector <long long> vPrefixSum;
	vPrefixSum.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	//first create prefix list (works)
	for (int i = 1; i < n + 1; i++) {
		vPrefixSum.push_back(vPrefixSum[i - 1] + v[i - 1]);
	}
	//take in + plug in values and print answer
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		cout << vPrefixSum[r] - vPrefixSum[l] << endl;
	}
}
