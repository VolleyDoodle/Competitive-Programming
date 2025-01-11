#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n;
    cin >> n;
    vector <vector <long long>> grid(n + 1, vector <long long>(n + 1, 0)); //pfs grid btw
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int tt;
            cin >> tt;
            grid[i][j] = (tt < 100 ? -1e8 : 0);
            if (tt == 100) grid[i][j]++;
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }
    //n^4 time complexity ;(
    //if in one big grid, everythign is good, then automatically in all subgrid it will be possible
    //and the problem statement also gave how to calcualte the grids?
    //fucking false mb
    //not sure, but i have never used 2d prefix sums on a usaco problem
    //so probably never gonna be on it (in silver atleast)
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int x = 1; x <= i; x++){
                for (int y = 1; y <= j; y++){
                    if (grid[i][j] - grid[x - 1][j] - grid[i][y - 1] + grid[x - 1][y - 1] > 0){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;

}