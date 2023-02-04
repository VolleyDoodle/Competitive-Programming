// blocks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    int n, count = 0;;
    cin >> n;
    string dice[4];
    string word, temp, ans = "NO";
    int r;
    int a[24][4];
    int a_temp[4], order[4] = {0, 1, 2, 3};
    bool first_letter = false, second_letter = false, third_letter = false, fourth_letter = false;
    for (int q = 0; q < 4; q++) {
        cin >> dice[q];
    }
    do
    {
        for (int i = 0; i < 4; i++) {
            a[count][i] = order[i];
        }
        count++;
    } while (next_permutation(order, order + 4));
    //print everything out
    /*for (int i = 0; i < 24; i++) {
        for (int x = 0; x < 4; x++) {
            cout << a[i][x] << " ";
        }
        cout << endl;
    }*/
    count = 0;
    for (int q = 0; q < n; q++) {
        cin >> word;
        r = word.length();
        for (int i = 0; i < 24; i++) {
            for (int x = 0; x < r; x++) {
                temp = dice[a[i][x]];
                //cout << temp << " ";
                for (int y = 0; y < 6; y++) {
                    if (temp[y] == word[x]) { count++; break; }
                }

            }
            if (count == r) { ans = "YES"; }
            //cout << "COUNT: " << count << endl;
            count = 0;
            //cout << endl;
        }
        cout << ans << endl;
        ans = "NO";
    }
    
}
