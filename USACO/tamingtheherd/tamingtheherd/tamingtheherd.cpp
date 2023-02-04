
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("taming.in");
    ofstream fout("taming.out");
    int n, change = 0;
    bool done = false;
    int maxB = 0, minB = 0;
    int a[101];
    fin >> n;
    for (int i = 0; i < n; i++) { fin >> a[i]; }
    a[0] = 0;
    //first find out common missing entries then calculate least and max
    for (int i = n - 1; i >= 0; i--) {
        if (change != 0 && a[i] != -1 && a[i] != change - 1) { fout << -1; done = true; break; }
        if (a[i] > 0) { change = a[i]; continue; }
       
        if (change > 0) { change--; a[i] = change; }
        

    }
    //for (int i = 0; i < n; i++) {fout << a[i] << " ";}
    //to calculate max add up #'s of -1 and 0's
    for (int i = 0; i < n; i++) {
        if (a[i] == -1 || a[i] == 0) { maxB++; }
    }
    //to calculate min 
    bool streak = 0; 
    for (int i= 0; i < n; i++) {
        if (a[i] == 0) { minB++; }
        if (a[i] == -1) { streak = true; }
        //if (streak && a[i] != -1) { minB++; streak = false; }
    }
    if (!done) {
        fout << minB << " " << maxB;
    }

}
