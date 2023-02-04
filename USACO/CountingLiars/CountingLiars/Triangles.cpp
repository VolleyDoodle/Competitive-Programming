

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n;
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    fin >> n;
    int triCords[100][2];
    int ans = 0, tempAns;
    for (int i = 0; i < n; i++) {
        fin >> triCords[i][0] >> triCords[i][1];
        //fout << triCords[i][0] << triCords[i][1] << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < n; c++) {
            for (int k = 0; k < n; k++) {
                if (triCords[i][0] == triCords[c][0] && triCords[i][1] == triCords[k][1]) {
                    tempAns = (triCords[c][1] - triCords[i][1]) * (triCords[k][0] - triCords[i][0]);
                    //fout << "RAN?" << endl;
                }
                //fout << tempAns << endl;
                if (tempAns < 0) {
                    tempAns *= -1;
                }
                if (tempAns > ans) {
                    ans = tempAns;
                }
                tempAns = 0;
            }
        }
    }
    fout << ans;

}

