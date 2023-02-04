// out_of_place.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    int n, ans = 0, temp;
    int data[100];
    fin >> n;
    for (int i = 0; i < n; i++) { fin >> data[i]; }
    for (int x = 0; x < n; x++) {
        
        for (int i = 0; i < n - 1; i++) {
            
            if (data[i] > data[i + 1]) {
                fout << "data[i + 1]: " << data[i + 1] << endl;
                fout << "data[i]: " << data[i] << endl;
                temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;
                ans++;
            }
        }
    }
    fout << ans;

}


