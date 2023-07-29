#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    char grid[11][11];
    for (int i = 0; i < a; i++){
        for (int x = 0; x < b; x++){
            cin >> grid[i][x];
        }
    }
    for (int i = 0; i < a; i++){
        for (int l = 0; l < c; l++){
            for (int j = 0; j < b; j++){
                for (int k = 0; k < c; k++){
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }  
    }
}