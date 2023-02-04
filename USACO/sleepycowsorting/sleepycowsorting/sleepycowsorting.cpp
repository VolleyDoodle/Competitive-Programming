
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");
    int n, ans = 0, index = 0, sorted = 0, count = 0;
    fin >> n;
    int cow[101], cowCheck[101];
    for (int i = 0; i < n; i++) { fin >> cow[i]; cowCheck[i] = cow[i]; }
    sort(cowCheck, cowCheck + n);
    //algo
    //if cow i is greater than cow x then switch
    while (true) {
        //fout << "turn: " << ans << endl;
        //check first
        for (int y = 0; y < n; y++) { if (cow[y] == cowCheck[y]) { count++; } }
        if (count == n) { fout << ans; break; }
        count = 0; ans++; sorted = 0;
        for (int y = n - 2; y >= 0; y--) {
            if (cow[y] < cow[y + 1]) { sorted++; }
            else { break; }
        }
        //fout << "I; " << index << endl;
        //use cow i
        for (int x = 1; x < n; x++) {
            if (cow[0] == cowCheck[0]) { index = n - 2 - sorted; }
            if (cow[0] > cow[x]) { index = x; }
            //change cow line

        }

        //fout << "i: " << index << endl;
        for (int y = 0; y < index; y++) { swap(cow[y], cow[y + 1]); }
        //for (int x = 0; x < n; x++) { fout << cow[x] << ' '; }
        index = 0;

    }
    //for (int i = 0; i < n; i++) { fout << cow[i] << ' '; }
}
