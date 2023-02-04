#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int n;
string a[11];
vector <int> findCords() {
    for (int i = n - 1; i >= 0; i--) {
        for (int x = n - 1; x >= 0; x--) {
            if (a[i][x] == '1') {
                return {x, i};
            }
        }
    }
    return { -1 };
}
int main()
{
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");


    fin >> n;
    int ans = 0; 
    vector <int> cords;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    //solve :0
    while (true) {
        cords = findCords();
        if (cords[0] == -1) { break; }
        else { 
            ans++; 
            for (int i = 0; i <= cords[1]; i++) {
                for (int x = 0; x <= cords[0]; x++) {
                    if (a[i][x] == '1') { a[i][x] = '0'; }
                    else { a[i][x] = '1'; }
                }
            }
        }
        
    }
    fout << ans;
}

