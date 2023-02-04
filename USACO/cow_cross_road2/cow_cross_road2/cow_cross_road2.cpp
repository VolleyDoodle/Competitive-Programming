// cow_cross_road2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map <char, int> sv;
    unordered_map <char, int> ev;
    char first_ch, second_ch, temp;
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
    int ans = 0;
    for (int i = 1; i <= 52; i++) {
        fin >> temp;
        //fout << "TEMP; " << temp;
        if (sv[temp] > 0) 
        { ev[temp] = i; 
        //fout << " VALUES: " << sv[temp] << " " << ev[temp] << endl; 
        }
        else{ sv[temp] = i;}
        
    }
    //intersecting if ABAB or BABA 
    for (const auto& x : sv) {
        //fout << x.first << " " << x.second << " " << ev[x.first] << endl;
        for (const auto& y: sv) {
            if (x.second < y.second && ev[x.first] > y.second && ev[x.first] < ev[y.first]) {
                //fout << "SUCESS 1: " << x.first << " "<<x.second << " " << ev[x.first] << " " << y.first <<" " << y.second << " " << ev[y.first] << endl;
                ans++;
            }
            else if (x.second > y.second && x.second < ev[y.first] && ev[x.first] > ev[y.first]) {
                //fout << "SUCESS 2: " << x.first << " " << x.second << " " << ev[x.first] << " " << y.first << " " << y.second << " " << ev[y.first] << endl;
                ans++;
            }
        }
    }
    fout << ans/2;
    



}
