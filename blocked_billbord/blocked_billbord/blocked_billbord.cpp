

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int program(int billboard[], int truck[]) {
    int xb, xt, yb, yt;
    if (billboard[0] > truck[2] || billboard[1] > truck[3] || billboard[2] < truck[0] || billboard[3] < truck[1]) {
        return 0;
    }
    else {
        xb = max(truck[0], billboard[0]);
        xt = min(billboard[2], truck[2]);
        yb = max(truck[1], billboard[1]);
        yt = min(truck[3], billboard[3]);
        return (xt - xb) * (yt - yb);
    }
}
int main()
{
    int fbill[4], sbill[4], truck[4];
    int ans;
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    for (int x = 0; x < 4; x++) { fin >> fbill[x]; fbill[x] = fbill[x] + 1000;  }
    for (int x = 0; x < 4; x++) { fin >> sbill[x]; sbill[x] = sbill[x] + 1000; }
    for (int x = 0; x < 4; x++) { fin >> truck[x]; truck[x] = truck[x] + 1000; }
    ans = (fbill[2] - fbill[0]) * (fbill[3] - fbill[1]);
    //fout << ans << endl;
    ans += (sbill[2] - sbill[0]) * (sbill[3] - sbill[1]);
    //fout << ans << endl;;
    ans -= program(fbill, truck) + program(sbill, truck);
    fout << ans << endl;
}

