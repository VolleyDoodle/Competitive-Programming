
#include <iostream>
#include <fstream>
using namespace std;
int a[1000][1001];
int main()
{
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    int n, q;
    cin >> n >> q;
    char space;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        for (int c = 1; c <= n; c++) {
            a[i][0] = 0;
            cin >> space; 
            if (space == '*') { curr++;}
            a[i][c] = curr;
        }
        curr = 0;
    }
    /*for (int i = 0; i < n; i++) {
        for (int c = 0; c <= n; c++) {
            cout << a[i][c] << " ";
        }
        cout << endl;
    }*/
    int x1, x2, y1, y2, ans = 0;
    for (int i = 0; i < q; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        for (int c = y1; c <= y2; c++) {
            //cout << a[c - 1][x1 - 1] << endl;
            //cout << a[c - 1][x2] << endl;
            ans+= a[c - 1][x2] - a[c - 1][x1 - 1];
        }
        cout << ans << endl;
        ans = 0;
        
    }
}

