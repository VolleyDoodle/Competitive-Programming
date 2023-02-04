
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    int n, ans = 0;
    bool substring = false;
    fin >> n;
    string a, b;
    fin >> a >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (!substring){
                ans++;
            }
            substring = true;
        }
        else { substring = false; }
        
        
    }
    fout << ans;

}


