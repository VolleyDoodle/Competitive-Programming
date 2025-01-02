#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    //literally just pigeonhole principle
    vector <vector <int>> grid(2, vector <int>(n));
    int black = 0, white = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
            if (grid[i][j] == '.'){
                if ((i + j)%2 == 1){
                    white++;
                } else{
                    black++;
                }
            }
            
        }
    }
    if (black != white){
        cout << "None";
        return;
    }
    //now just differenitate
    //from multiple or unique
    //conjecture : unique only if the segment of dots(.) is odd
    //
    
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