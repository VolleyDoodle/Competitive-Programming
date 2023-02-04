// the_bovine_shuffle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n;
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    fin >> n;
    int moves[101], cows[101], ans[101];
    for (int i = 1; i <= n; i++) {
        fin >> moves[i];
    }
    for (int i = 1; i <= n; i++) {
        fin >> cows[i];
    }
    for (int i = 1; i <= 3; i++) {
        for (int c = 1; c <= n; c++) {
            //fout<<cows[moves[c]] << " " << moves[c] << endl;
            ans[c] = cows[moves[c]];
            
            //ans[moves[c]] = cows[c];
        }
        for (int k = 1; k <= n; k++) {
            
            cows[k] = ans[k];
            //fout << "cowsk " << cows[k] << endl;
        }
    }
    for (int i = 1; i <= n; i++) {
        fout << ans[i] << endl;
    }
    //swithc



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
