
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int ans = 0;
int a[10][2];
int n;
void solve(int b[][2], int c) {
    for (int i = 0; i < n; i++) {
        b[c][0] = i;
        for (int x = 0; x < n; x++) {
            if (x != i) { b[c][1] = x; solve(n, ) }
        }
    }

}
int main()
{
    ifstream fin("wormholes.in");
    ofstream fout("wormholes.out");
    fin >> n;
    int temp, temp1;
    int b[5][2];
    for (int i = 0; i < n; i++) { 
        fin >> a[i][0] >> a[i][1];

    }
    solve(b, 0);
    fout << ans;

}