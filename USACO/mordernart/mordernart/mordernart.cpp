
#include <iostream>
#include <fstream>
#include <set>
using namespace std;
int main()
{
    ifstream fin("art.in");
    ofstream fout("art.out");
    int n, ans = 0, index = 0;
    string canvas[10];
    int cords[9][4];
    int bottom = 21, left = 21, top = -1, right = -1;
    //maybe save cordinates (bl ,tr) bottom left, top right
    set <char> paints;
    fin >> n;
    for (int i = n - 1; i >=0; i--) {
        fin >> canvas[i];
        for (int x = 0; x < n; x++) {    
            if (canvas[i][x] != '0') { paints.insert(canvas[i][x]); }
        }
    }
    //for (char paint : paints) { fout << paint << " "; } fout << endl;
    //calculate possible cords for all paints
    for (char paint : paints) {
        cords[index][2] = -1;cords[index][0] = 21;cords[index][1] = 21;
        for (int i = 0; i < n; i++) {
            for (int x = 0; x < n; x++) {
                if (canvas[i][x] == paint){
                    cords[index][3] = i;cords[index][2] = max(cords[index][2], x);
                    cords[index][0] = min(cords[index][0], x);cords[index][1] = min(cords[index][1], i);
                }
            }
        }
        for (int i = 0; i < 4; i++) { fout << cords[index][i] << ' '; }
        fout << endl;
        index++;
    }
    //try for every color on canvas and see 
    //if it possible for it to be painted first
    int paintIndex = 0;
    bool checkBoard[10][10];
    for (int i = 0; i < n; i++) { for (int x = 0; x < n; x++) { checkBoard[i][x] = false;  } }
    bool possible = true;
    for (char paint : paints) { //loops through set paints
        //check if "paint" is layered on top of another paint
        //if yes then cannot be painted first
        index = 0;
        for (char paint2 : paints) {
            if (paint2 == paint) { index++; continue; }
            for (int i = cords[index][1]; i <= cords[index][3]; i++) {
                for (int x = cords[index][0]; x <= cords[index][2]; x++) {
                    checkBoard[i][x] = true;
                }
            }
            for (int i = cords[paintIndex][1]; i <= cords[paintIndex][3]; i++) {
                for (int x = cords[paintIndex][0]; x <= cords[paintIndex][2]; x++) {
                    if (checkBoard[i][x] && canvas[i][x] == paint) { possible = false; }
                }
            }
            //fout << "p: " << possible << endl;
            for (int i = 0; i < n; i++) { for (int x = 0; x < n; x++) { checkBoard[i][x] = false; } }
            index++;
        }
        if (possible) { ans++; }
        possible = true;
        paintIndex++;
    }
    if (ans == 0) { ans = 1; }
    fout << ans;
}