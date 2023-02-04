
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    int a[4][2];
    int silver = 0, gold = 0, plat = 0;
    for (int i = 0; i < 4; i++) {
        for (int x = 0; x < 2; x++) {
            fin >> a[i][x];
        }
    }
    silver += (a[1][1] - a[1][0]) + (a[2][1] - a[2][0]) + (a[3][1] - a[3][0]);
    gold+= (a[2][1] - a[2][0]) + (a[3][1] - a[3][0]);
    plat += (a[3][1] - a[3][0]);
    fout << silver << endl;
    fout << gold << endl;
    fout << plat << endl;
}

