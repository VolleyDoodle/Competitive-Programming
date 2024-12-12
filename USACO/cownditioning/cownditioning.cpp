
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, temp;
	int countCheck;
	int minVal = 10001;
	cin >> n;
	int s = 0, ans = 0, i_pos;
	vector <int> a(n);
	vector <int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> temp; a.at(i) = temp; ////cout << a[i] << endl; 
	}
	for (int i = 0; i < n; i++) {
		cin >> temp; b.at(i) = temp; ////cout << b[i] << endl; 
	}
	while (true) {
		if (a[s] == b[s]) { s++; }
		if (s == n) {
			break;
		}
		if (a[s] > b[s]) {
			//cout << b[s] << " ";
			ans++;
			//cout << "RAN1" << endl;
			for (int i = s; i < n; i++){
				if (a[i] <= b[i]) { 
					break;
					//cout << b[i] << "->";  
					
					//cout << b[i] << " ";
				}
				
				else { b.at(i) = b[i] + 1; }
			}
			////cout << endl;
		}
		else if (a[s] < b[s]) {
			//cout << b[s] << " ";
			//cout << "RAN2" << endl;
			ans++;
			for (int i = s; i < n; i++) {
				if (a[i] >= b[i]) { 
					//cout << b[i] << "->"; 
					break;
					//cout << b[i] << " ";
				}
				else { b.at(i) = b[i] - 1;  }
			}
		}
	}
	cout << ans;
}