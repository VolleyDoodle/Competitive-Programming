

#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
int index(int a[], int b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == b) {
            return i;
        }
    }
}
int main()
{
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int n, temp_ans = 0;
    int a, b, g;
    int cans[3] = { 1, 2, 3 };
    int ans[3] = { 0, 0, 0 };
    bool bCans[3] = { false, false, false };
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a >> b >> g;
        //fout << cans[index(cans, a, n)] << " " << cans[index(cans, b, n)] << endl;
        swap(cans[index(cans, a, n)], cans[index(cans, b, n)]);
        for (int x = 0; x < 3; x++) {
            bCans[x] = true;
            //switch ints
            //fout << "tf " <<bCans[index(cans, g, n)] << endl;
            if (bCans[index(cans, g, n)] == true) {
                ans[x]++;
            }
            bCans[x] = false;
        }
    }
    fout << max(ans[0], max(ans[1], ans[2]));

}

