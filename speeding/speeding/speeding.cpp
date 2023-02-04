

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int n, m, ans = 0, tans = 0;
    int i_n = 0, i_m = 0;
    fin >> n >> m;
    bool did = false;
    int data_n[100][2], data_m[100][2];
    for (int i = 0; i < n; i++) {
        fin >> data_n[i][0] >> data_n[i][1];

    }
    for (int i = 0; i < m; i++) { fin >> data_m[i][0] >> data_m[i][1]; }
    for (int i = 1; i <= 100; i++) {
        if (i > data_n[i_n][0] && i_n != n - 1) { 
            i_n++; did = false; 
            data_n[i_n][0] += data_n[i_n - 1][0];
        }
        if (i > data_m[i_m][0] && i_m != m - 1) 
        { 
            i_m++; did = false; 
            data_m[i_m][0] += data_m[i_m - 1][0];
        }
        //fout << i_n << " " << i_m << endl;
        //fout << data_n[i_n][0] << " " << data_m[i_m][0] << endl;
        if (data_m[i_m][1] > data_n[i_n][1] && !did) { tans = data_m[i_m][1] - data_n[i_n][1]; did = true; }
        ans = max(ans, tans);
        //fout << "ans " << ans << " i: " << i << endl;
    }
    fout << ans;
    
}


