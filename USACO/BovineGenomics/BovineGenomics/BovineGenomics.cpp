
#include <iostream>
#include <fstream>
using namespace std;
void check(int i, bool dna[],  string dnaSeq) {
	if (dnaSeq[i] == 'A') { dna[0] = true; }
	if (dnaSeq[i] == 'C') { dna[1] = true; }
	if (dnaSeq[i] == 'G') { dna[2] = true; }
	if (dnaSeq[i] == 'T') { dna[3] = true; }

}
int main()
{
	int n, m, ans = 0;
	ifstream fin("cownomics.in");
	ofstream fout("cownomics.out");
	string spottyDnaSeq[100];
	string plainDnaSeq[100];
	bool spottyDna[4];
	bool plainDna[4];
	for (int i = 0; i < 4; i++) {
		spottyDna[i] = false;
		plainDna[i] = false;
	}
	fin >> n >> m;
	for (int i = 0; i < n; i++) {
		fin >> spottyDnaSeq[i];
		
	}
	for (int i = 0; i < n; i++) {
		fin >> plainDnaSeq[i];
	}
	for (int c = 0; c < m; c++) {
		for (int k = 0; k < n; k++) {
			check(c, spottyDna, spottyDnaSeq[k]);
		}
		for (int r = 0; r < n; r++){
			check(c, plainDna, plainDnaSeq[r]);
		}
		for (int y = 0; y < 4; y++) {
			//fout << spottyDna[y] << plainDna[y] << endl;
			if (plainDna[y] == true && spottyDna[y] == true) {
				ans++;
				
				break;
			}
		}
		for (int o = 0; o < 4; o++) {
			plainDna[o] = false;
			spottyDna[o] = false;
		}

	}
	fout << m - ans;



}


