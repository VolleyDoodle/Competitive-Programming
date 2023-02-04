
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int x = 2, y = 3;
    ofstream fout("debug.out");
    //cout << ceil(float(1 + 100) / float(2)) << endl;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        vector <int> towers;
        int ftower; cin >> ftower;
        for (int x = 0; x < n - 1; x++) {
            int tower; cin >> tower; towers.push_back(tower);
            //cout << ftower << tower;
            
        }
        sort(towers.begin(), towers.end());
        for (int x = 0; x < n - 1; x++) {
            if (towers[x] > ftower) {
                ftower = ceil((double(ftower) + double (towers[x])) / ((double)(2)));
            }
            
        }
        cout << ftower << endl;
    }
}

