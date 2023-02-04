
#include <iostream>
#include <algorithm>  
#include <fstream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;
int main()
{
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int n, B, ans = INT_MAX;
    int upperLeft = 0, lowerLeft = 0, upperRight = 0, lowerRight = 0;
    fin >> n >> B;
    int data[101][2], xc[101], yc[101];
    unordered_set <int> sxc, syc;
    sxc.insert(0); syc.insert(0);
    for (int i = 0; i < n; i++) { 
        fin >> data[i][0] >> data[i][1];
        xc[i] = data[i][0]; yc[i] = data[i][1];
    }
    //sort(data.begin(), data.end());
    //sort(cords, cords + n, [](int a[2], int b[2]) { return a[0] > b[0]; });
    sort(xc, xc + n);
    sort(yc, yc + n);
    for (int i = 0; i < n; i++) {
        sxc.insert(xc[i] - 1);  syc.insert(yc[i] - 1);
        //fout << xc[i] << " " << yc[i];
        //fout << endl;
    }
    for (int x : sxc) {
        for (int y : syc) {
            //fout << x << " " << y << endl;
            for (int i = 0; i < n; i++) {
                if (data[i][0] > x && data[i][1] > y) { upperRight++; }
                else if (data[i][0] > x && data[i][1] < y) { lowerLeft++; }
                else if (data[i][0] < x && data[i][1] > y) { lowerRight++; }
                else { upperLeft++; }
            }
            //if (x == 6 && y == 4) {fout << upperRight << lowerRight << upperLeft << lowerLeft << endl;}
            //return max amt cows
            ans = min(ans, max(max(upperRight, lowerRight), max(upperLeft, lowerLeft)));
            upperRight = 0; upperLeft = 0; lowerRight = 0; lowerLeft = 0;
        }
    }
    fout << ans;
}

