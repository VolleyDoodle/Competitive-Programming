
#include <fstream>
#include <iostream>
using namespace std;
int grid[1001][1001];
int main() {
    //similar technique to restaurant customers???
    //ifstream cin("paintbarn.in");
    //ofstream fout("paintbarn.out"); 
    int n, k, bx, by, tx, ty;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> bx >> by >> tx >> ty;
        for (int i = by; i < ty; i++) {
            grid[i][bx]++; grid[i][tx]--;
        }
    }
    //now check row by row
    int curr = 0, ans = 0;
    for (int i = 0; i < 1001; i++) {
        for (int x = 0; x < 1001; x++) {
            curr += grid[i][x];
            //if (grid[i][x] > 0) { curr+=grid[i][x]; }
            //else if (grid[i][x] < 0) { curr-=grid[i]; }
            if (curr == k) { ans++; }
        }
        curr = 0;
    }
    cout << ans;
}

