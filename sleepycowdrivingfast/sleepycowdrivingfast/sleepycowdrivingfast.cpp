
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");
    int n, ans = 0;
    fin >> n;
    int a[101];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) { ans = i + 1; }
    }
    fout << ans;
}

