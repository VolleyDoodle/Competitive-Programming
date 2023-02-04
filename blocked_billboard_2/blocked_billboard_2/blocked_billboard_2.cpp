

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int a[4], b[4];
    int xb, xt, yb, yt, area, ans;
    for (int x = 0; x < 4; x++) { fin >> a[x]; a[x] += 1000; }
    for (int x = 0; x < 4; x++) { fin >> b[x]; b[x] += 1000; }
    xb = max(a[0], b[0]);
    xt = min(a[2], b[2]);
    yb = max(a[1], b[1]);
    yt = min(a[3], b[3]);
    area = (xt - xb) * (yt - yb);
    //fout << area;
    if (area > 0) {
        if (b[0] <= a[0] && b[2] >= a[2] && (b[1] <= a[1] || b[3] >= a[3])) {
            ans = (a[2] - a[0]) * (a[3] - a[1]) - area;
            fout << ans;
        }
        else if (b[1] <= a[1] && b[3] >= a[3] && (b[0] <= a[0] || b[2] >= a[2])) {
            ans = (a[2] - a[0]) * (a[3] - a[1]) - area;
            fout << ans;
        }
        else {
            fout << (a[2] - a[0]) * (a[3] - a[1]);
        }
    }
    
    if (area <= 0) {
        fout << (a[2] - a[0]) * (a[3] - a[1]);
    }

}

