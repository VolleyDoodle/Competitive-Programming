
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int start[1000002], endt[1000002];
int main()
{
    ifstream fin("stacking.in");
    ofstream fout("stacking.out");
    int n, k;

    fin >> n >> k;
    int kk = k;
    vector <int> haybales(n + 1);
    while (k--) {
        int a, b;
        fin >> a >> b;
        start[a]++; endt[b]--;
    }
    int curAdd = 0;
    for (int i = 1; i <= n; i++) {
        if (start[i] > 0) {
            curAdd += start[i];
        }
        haybales[i] += curAdd;
        if (endt[i] < 0) {
            curAdd += endt[i];
        }
    }

    sort(haybales.begin() + 1, haybales.end());
    fout << haybales[n / 2 + 1] << endl;


}

