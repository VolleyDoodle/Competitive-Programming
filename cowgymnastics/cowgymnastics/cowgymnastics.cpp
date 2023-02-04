// cowgymnastics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    int n, x;
    int first_num, second_num, counter = 0;
    int first_pos = 9999, second_pos = 9999, ans = 0;
    bool ran1 = false, ran2 = false;
    fin >> n >> x;
    int cowData[10][20];
    for (int i = 0; i < n; i++){
        for (int c = 0; c < x; c++) {
            fin >> cowData[i][c];
        }
    }
    for (int c = 0; c < x; c++) {
        first_num = cowData[0][c];
        for (int d = 0; d < x; d++) {
            second_num = cowData[0][d];
            //fout << "DATA: " << first_num << " " << second_num << endl;
            for (int i = 0; i < n; i++) {
                for (int h = 0; h < x; h++) {
                    if (cowData[i][h] == first_num) {
                        ran1 = true;
                        first_pos = h;
                        //fout << "FIRST_POS " << first_pos << endl;
                    }
                    if (cowData[i][h] == second_num) {
                        ran2 = true;
                        second_pos = h;
                        //fout << "SECOND_POS " << second_pos << endl;
                    }
                    //fout << "COUNTER " << counter << endl;   
                }
                if (first_pos < second_pos && ran1 && ran2) { counter++; }
                first_pos = 9999; second_pos = 9999;
            }
            if (counter == n) {
                ans++;
            }
            //fout << "ANS: " << ans << endl;
            counter = 0;
        }
    }
    fout << ans;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

