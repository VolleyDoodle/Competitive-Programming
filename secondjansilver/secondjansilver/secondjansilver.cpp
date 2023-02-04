#include <iostream>
#include <fstream>
using namespace std;
int grid[1501][1501];
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int n;
    int tempp;
    fin >> n;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for (int x = 0; x < n; x++) {
            //r = -1, d = -2
            if (temp[x] == 'R') { grid[i][x] = -1; }
            else if (temp[x] == 'D') { grid[i][x] = -2; }
        }
        cin >> tempp; grid[i][n] = tempp;
    }
    for (int x = 0; x < n; x++) {
        cin >> tempp;
        //cout << tempp << endl;
        grid[n][x] = tempp;
    }

}
