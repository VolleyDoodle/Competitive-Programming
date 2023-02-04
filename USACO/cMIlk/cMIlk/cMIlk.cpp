
#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;
int main()
{
    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");
    unordered_set<int> milk, bMilk, peopleDrank;
    int n, m, d, s;
    int bMilkCounter = 0;
    int temp_ans, ans = 0;
    int dData[1001][3];
    int sData[50][2];
    fin >> n >> m >> d >> s;
    for (int i = 0; i < d; i++) {
        fin >> dData[i][0] >> dData[i][1] >> dData[i][2];
        // person, milk, time
        milk.insert(dData[i][1]);
    }
    for (int i = 0; i < s; i++) {
        fin >> sData[i][0] >> sData[i][1];
        //person, time
    }
    for (int i : milk) {
        for (int x = 0; x < s; x++) {
            for (int y = 0; y < d; y++) {
                if (dData[y][1] == i && sData[x][1] > dData[y][2] && dData[y][0] == sData[x][0]) {
                    bMilkCounter++;
                    break;
                }
            }
        }
        if (bMilkCounter == s) { bMilk.insert(i); }
        bMilkCounter = 0;
    }
    //calculating max antidotes
    for (int i : bMilk) {
        for (int x = 0; x < d; x++) {
            if (dData[x][1] == i) { peopleDrank.insert(dData[x][0]); }
        }
        temp_ans = peopleDrank.size();
        ans = max(ans, temp_ans);
        peopleDrank.clear();
    }
    fout << ans;
}

