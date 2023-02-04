

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("square.in");
    ofstream fout("square.out");
    int a[4], b[4];
    for (int x = 0; x < 4; x++) { fin >> a[x]; }
    for (int x = 0; x < 4; x++) { fin >> b[x]; }
    int xb, xt, yb, yt, side;
    xb = min(a[0], b[0]);
    xt = max(a[2], b[2]);
    yb = min(a[1], b[1]);
    yt = max(a[3], b[3]);
    side = max(xt - xb, yt - yb);
    fout << side * side;
}


