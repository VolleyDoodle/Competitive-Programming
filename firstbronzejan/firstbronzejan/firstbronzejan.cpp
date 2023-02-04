#include <fstream>
#include <vector>
using namespace std;

#include <iostream>

int main()
{
	//ifstream fin("input.in");
	//ofstream fout("out.out");
	vector <int> clist;
	int n;
	cin >> n;
	string cline;
	cin >> cline;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp; clist.push_back(temp);
	}
	int minH = -1, maxH = -1, minG = -1, maxG = -1;
	for (int i = 0; i < n; i++) {
		if (cline[i] == 'G') { 
			maxG = i;
			if (minG == -1) {

				minG = i;
			}
		}
		else if (cline[i] == 'H') {
			maxH = i;
			if (minH == -1) {
				minH = i;
			}
		}
	}
	//cout << "maxG: " << maxG << "| minG: " << minG << endl;
	//cout << "maxH: " << maxH << "| minH: " << minH << endl;
	int leaderH = -1, leaderG = -1;
	if (clist[minH] - 1 >= maxH) {
		leaderH = minH;
	}
	if (clist[minG] - 1 >= maxG) {
		leaderG = minG;
	}
	//cout << leaderH << " " << leaderG;
	int ans = 0;
	if (leaderH >= 0 && leaderG >= 0) {
		ans++;
	}
	
	for (int i = 0; i < n; i++) {
		if (cline[i] == 'G' && clist[i] - 1 >= leaderH && i < leaderH) {
			ans++;
		}
		else if (cline[i] == 'H' && clist[i] - 1 >= leaderG && i < leaderG) {
			ans++;
		}
	}
	cout << ans;

}

