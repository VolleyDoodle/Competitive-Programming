

#include <iostream>
#include <fstream>

using namespace std;
int arrGrid[1205][1205];
int pfsGrid[1205][1205];
int main()
{
    ifstream fin("lazy.in");
    ofstream fout("lazy.out");
    int n, k;
    fin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= n; x++) {
            int t; fin >> t; arrGrid[i][x] = t;
            pfsGrid[i][x] = arrGrid[i][x] + pfsGrid[i - 1][x] + pfsGrid[i][x - 1] - pfsGrid[i - 1][x - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //(i, j) is Bessie's location

        }
    }
    

}

