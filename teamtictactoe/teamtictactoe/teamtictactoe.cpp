
#include <iostream>
#include <fstream>
#include <set>
using namespace std;
int main()
{
    string board[3];
    ifstream fin("tttt.in");
    ofstream fout("tttt.out");
    set <char> singleCows, sTemp;
    set <set <char>> doubleCows;
    for (int i = 0; i < 3; i++) {
        fin >> board[i];
    }
    //first check single cow winners
    //check rows && columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            singleCows.insert(board[i][0]);
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            singleCows.insert(board[0][i]);
        }
    }
    //check diagonals
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) { singleCows.insert(board[1][1]); }
    if (board[2][2] == board[1][1] && board[1][1] == board[0][0]) { singleCows.insert(board[1][1]); }
    fout << singleCows.size() << endl;
    //check double cow winners
    //check row
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 3; x++) {
            sTemp.insert(board[i][x]);
        }
        if (sTemp.size() == 2) { doubleCows.insert(sTemp); }
        sTemp.clear();
    }
    //check column
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 3; x++) {
            sTemp.insert(board[x][i]);
        }
        if (sTemp.size() == 2) { doubleCows.insert(sTemp); }
        sTemp.clear();
    }
    //check diagonals
    sTemp.insert(board[1][1]); sTemp.insert(board[0][0]); sTemp.insert(board[2][2]);
    if (sTemp.size() == 2){ doubleCows.insert(sTemp); }
    sTemp.clear();
    sTemp.insert(board[1][1]); sTemp.insert(board[0][2]); sTemp.insert(board[2][0]);
    if (sTemp.size() == 2) { doubleCows.insert(sTemp); }
    fout << doubleCows.size();

}

