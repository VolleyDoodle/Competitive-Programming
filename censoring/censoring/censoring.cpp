// censoring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("censor.in");
    ofstream fout("censor.out");
    string data;
    string censor;
    string ans = "";
    fin >> data >> censor;
    for (int i = 0; i < data.length(); i++) {
        ans += data[i];
        //cout << ans << endl;
        if (ans.length() >= censor.length()){
            //cout << "r";
            //cout << ans.substr(ans.length() - censor.length()) << endl;
            if (ans.substr(ans.length() - censor.length()) == censor) {
                cout << "dd";
                ans.erase(ans.length() - censor.length());
            }
        }
    }
    fout << ans;

}

