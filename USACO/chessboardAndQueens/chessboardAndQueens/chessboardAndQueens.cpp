
#include <iostream>
#include <cstring>
using namespace std;


int ans = 0;


void solve(int row, string board[], bool c[], bool d1[], bool d2[]) {
    if (row == 8) { ans++; return; }
    for (int y = 0; y < 8; y++) {
        if (board[row][y] == '*' || c[y] || d1[row + y] || d2[row - y + 7]) { continue; } //queens attacking each other or spot taken
        c[y] = true; d1[row + y] = true; d2[row - y + 7] = true;
        solve(row + 1, board, c, d1, d2);
        c[y] = false; d1[row + y] = false; d2[row - y + 7] = false;
    }

}
int main()
{

    int row = 0;
    bool c[9], d1[15], d2[15];
    string board[8];
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    memset(c, 0, sizeof(c));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    solve(0, board, c, d1, d2);
    cout << ans;


    
}

