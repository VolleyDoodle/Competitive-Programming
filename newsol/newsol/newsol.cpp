
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    //ifstream fin("input.in");
    //ofstream fout("output.out");
    int n;
    cin >> n;
    string s("MOO");
    string o("MOM");
    for (int i = 0; i < n; i++) {
        int ans = -1;
        string temp;
        cin >> temp;
        int len = temp.length();
        
        
        if (temp.find("OOM") != string::npos) {
            ans = temp.length() - 1;
            
        }
        if (temp.find("OOO") != string::npos) {
            ans = temp.length() - 2;
            
        }
        if (temp.find("MOM") != string::npos) {
            ans = temp.length() - 2;

        }
        if (temp.find("MOO") != string::npos) {
            ans = temp.length() - 3;
            
        }
        if (ans >= 0) {
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }

    }
}