
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool checked[9];

    

int main()
{
    //first generate all possibilites and check
    //then sort the checked ones and print it out
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    string cows[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    sort(cows, cows + 8);
    string dCows[10][2];
    int n;
    bool done = true;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> dCows[i][0];
        for (int x = 0; x < 5; x++) { fin >> dCows[i][1]; }
    }
    do {
        //check cows to see if works

        for (int i = 0; i < 8; i++) {
            for (int x = 0; x < n; x++) {
                if (cows[i] == dCows[x][0]) {
                    if (i == 0) {
                        //fout << cows[i + 1] << " " << endl;
                        if (cows[i + 1] == dCows[x][1]) { continue; }
                        else { done = false; break; }
                    }
                    else if (i == 7) {
                        if (cows[i - 1] == dCows[x][1]) { continue; }
                        else { done = false; break; }
                    }
                    else {
                        if (cows[i + 1] == dCows[x][1] || cows[i - 1] == dCows[x][1]) { continue; }
                        else { done = false; break; }
                    }
                }
            }
            if (done == false) { break; }
            //fout << dCows[val][1] << " ";
            
        }
        //fout << endl;
        if (done == true){
            for (int i = 0; i < 8; i++) { fout << cows[i] << endl; }
            break;
        }
        done = true;
        //for (int i = 0; i < 8; i++) { fout << cows[i] << ""; }
    } while (next_permutation(cows, cows + 8));


}

