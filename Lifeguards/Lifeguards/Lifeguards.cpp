// Lifeguards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int overlapfn(int c, int end[], int start[], int overlap[]) {
    int temp = 0;
    for (int k = start[c]; k <= end[c]; k++) {
        if (overlap[k] != 1) {
            overlap[k] = 1;
            temp++;
        }
    }
    return temp;

}
int main()
{
    int start[100];
    int end[100];
    int overlap[1000];
    int n;
    int tempAns = 0, ans = 0;
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> start[i] >> end[i];
    }

    for (int i = 0; i < n; i++) {
        for (int c = 0; c < n; c++) {
            if (i != c) {
                //tempAns+=overlapfn(c, end, start, overlap);
                //fout << "overlapfn(temp) " << overlapfn(c, end, start, overlap) << endl;
                for (int k = start[c] + 1; k <= end[c]; k++) {
                    if (overlap[k] != 1) {
                        overlap[k] = 1;
                        tempAns++;
                    }
                } 
                //fout <<"StartEnd[c] " << start[c] << " " << end[c] << endl;
            }
        }
        //fout << "tempans " << tempAns << endl;
        if (tempAns > ans) {
            ans = tempAns;
        }
        tempAns = 0;
        for (int k = 0; k < 1000; k++) {
            overlap[k] = 0;
        }
    }
    //fout << "ANs " << ans;
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
