
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    //ifstream fin("input.in");
    //ofstream fout("output.out");
    int n;
    fin >> n;
    string s("MOO");
    for (int i = 0; i < n; i++) {
        int ans = 0;
        string temp;
        fin >> temp;
        int len = temp.length();
        if (temp.find(s) != string::npos) {
            ans = temp.length() - 3;
            fout << ans << endl;
        }
        else {
            
            while (temp[temp.length() - 2] == 'M') {
                if (temp.length() <= 3) {
                    
                    ans = -1;
                    break;
                }
                ans++;
                temp.erase(temp.length() - 1);
            }
            while (temp[1] == 'M') {
                if (temp.length() <= 3) {

                    ans = -1;
                    break;
                }
                ans++;
                temp.erase(0, 1);
            }
            bool bad = false;
            if (ans == -1) {
                bad = true;
                fout << -1 << endl;
            }
            if (temp[temp.length() - 1] == 'M') {
                
                ans++;
                temp[temp.length() - 1] = 'O';
            }
            if (!bad) {
                ans += temp.length() - 3;
                temp.erase(0, temp.length() - 3);
                
                if (temp[0] == 'O') {
                    temp[0] = 'M';
                    ans++;
                }
                fout << ans << endl;
            }
            

        }
        
    }
}

