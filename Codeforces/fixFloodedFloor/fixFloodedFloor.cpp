#include <bits/stdc++.h>
using namespace std;
int n;
bool inGrid(int i, int j){
    if (i < 0 || i > 1 || j < 0 || j >= n) return false;
    return true;
}
void solve(){

    cin >> n;
    vector <vector <int>> grid(2, vector <int>(n));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            grid[i][j] = (c == '.' ? 1 : 0);
        }
    }
    grid[0].push_back(0);
    grid[1].push_back(0);
    //1 is equal to empty,
    //0 is equal to full
    bool pos = true, multi = false;
    for (int i = 0; i < n; i++){
        //go by column by column
        //case 1
        if (grid[0][i] + grid[1][i] == 1){
            if (grid[0][i] == 1 && grid[0][i + 1] == 1){
                grid[0][i] = 0;
                grid[0][i + 1] = 0;
            } else if (grid[1][i] == 1 && grid[1][i + 1] == 1){
                grid[1][i] = 0;
                grid[1][i + 1] = 0;
            } else{
                pos = false;
                break;
            }
        } else if (grid[0][i] + grid[1][i] == 2){
            //now there is a empty column
            //can be multiple if 4x4 square
            if (grid[0][i] + grid[1][i] + grid[0][i + 1] + grid[1][i + 1] == 4){
                multi = true;
                grid[0][i + 1] = 1;
                grid[1][i + 1] = 1;
            }
            grid[0][i] = 1;
            grid[1][i] = 1;
        }
    }
    if (!pos){
        cout << "None";
    } else if (multi){
        cout << "Multiple";
    } else{
        cout << "Unique";
    }

}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}