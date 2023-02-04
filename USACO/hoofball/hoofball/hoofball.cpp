#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{

    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");

    int a[101], aPassed[101];
    bool passed[101]; //array to track # of cows cow[i] gets ball from
    int n, ans = 0;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
        aPassed[i] = 0;
    }

    sort(a, a + n);
    //for (int i = 0; i < n; i++) { fout << a[i] << ' '; }     
    //fout << endl;
    for (int i = 0; i < n; i++) {
        if (i == 0) { passed[i] = true; }
        else if (i == n - 1) { passed[i] = false; }
        else {
            passed[i] = a[i + 1] - a[i] < a[i] - a[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        if (passed[i]) { aPassed[i + 1]++; }
        else if (!passed[i]) { aPassed[i - 1]++; }
    }

    for (int i = 0; i < n; i++) {
        if (aPassed[i] == 0) { ans++; }
        //if (passed[i] == !passed[i + 1]){ aPassed[i] = aPassed[i + 1] = 2; }
        if (passed[i] && !passed[i + 1] && aPassed[i] == 1 && aPassed[i + 1] == 1 && i != n - 1)
        {
            //fout << i << " " << i + 1 << endl;
            aPassed[i] = aPassed[i + 1] = 2;
            ans++;
        } //oscilating and no other cow passes ball to them

    }
    if (ans == 0) { ans = 1; }
    fout << ans;

}