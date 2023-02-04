

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int start[100], end[100], buckets[100];
    int tempAns = 0, ans = 0;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> start[i] >> end[i] >> buckets[i];
    }
    //logic
    for (int i = 1; i <= 1000; i++) {
        for (int c = 0; c < n; c++) {
            if (start[c] <= i && end[c] >= i) {
                tempAns += buckets[c];
            }
        }
        if (tempAns > ans) {
            ans = tempAns;
        }
        tempAns = 0;
    }
    fout << ans;

}

