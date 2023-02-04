// MilkPailes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int x, y, m;
    int milkAmount, ans = 0;
    fin >> x >> y >> m;
    //fout << x << y << m << endl;
    for (int i = 0; i * x < m; i++) {
        milkAmount = x * i;
        //fout << milkAmount << " Start" << " ";
        for (int c = 0; milkAmount < m; c++) {
            milkAmount += y;    
        }
        milkAmount -= y;
        //fout << milkAmount - y << endl;
        if (milkAmount > ans) {
            ans = milkAmount;
        }
    }
    fout << ans;
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
