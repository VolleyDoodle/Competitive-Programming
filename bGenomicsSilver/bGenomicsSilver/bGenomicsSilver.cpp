
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
	int n, m, ans = 0;
	ifstream fin("cownomics.in");
	ofstream fout("cownomics.out");
	//string spottyDnaSeq[501];
	//string plainDnaSeq[501];
	vector <string> spottyDnaSeq, plainDnaSeq;
	string temp, temp1, temp2;
	unordered_map<string, bool> dCSpotty, dCPlain;
	bool done = false;
	fin >> n >> m;
	for (int i = 0; i < n; i++) {
		fin >> temp; spottyDnaSeq.push_back(temp);

	}
	for (int i = 0; i < n; i++) {
		fin >> temp; plainDnaSeq.push_back(temp);
	}
	for (int x = 0; x < m; x++) {
		for (int y = x + 1; y < m; y++) {
			for (int j = y + 1; j < m; j++) {
				ans++;
				for (int i = 0; i < n; i++) {
					temp1 = ""; temp2 = "";
					temp = spottyDnaSeq[i]; temp1 += temp[x]; temp1 += temp[y]; temp1 += temp[j];				
					dCSpotty[temp1] = true;
					temp = plainDnaSeq[i]; temp2 += temp[x]; temp2 += temp[y]; temp2 += temp[j];
					dCPlain[temp2] = true;
					if (dCSpotty[temp2] || dCPlain[temp1]) { ans--; break; }

				}
				dCSpotty.clear(); dCPlain.clear();
				
			}

		}
	}
	fout <<  ans;



}