#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
//easy as fuck proble but for some reason whoever creates the editorial
//is fucking retarted and cant explain for shit
int n;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
vector <vector <int>> make_grid(int i, int j, vector <int>& freq, vector <vector <int>>& grid){
    vector <vector <int>> ans(n, vector <int>(n));
    vector <int> row(n), col(n);
    for (int c = 0; c < n; c++){
        col[c] = freq[grid[i][c]];
    }
    for (int r = 0; r < n; r++){
        //traversing over rows so use j
        row[r] = freq[grid[r][j]];
    }
    for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
            ans[r][c] = row[r] + col[c];
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");

    cin >> n;
    vector <vector <int>> grid(n, vector <int>(n));
    vector <int> freq(2 * n + 1, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
            freq[grid[i][j]]++;
        }
    }
    vector <pair <int, int>> oneSpots;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (freq[grid[i][j]] == 1){
                oneSpots.push_back({i, j});
            }
        }
    }
    vector <vector <int>> ans1(n, vector <int>(n)), ans2(n, vector <int>(n));
    ans1 = make_grid(oneSpots[0].f, oneSpots[0].s, freq, grid);
    ans2 = make_grid(oneSpots[1].f, oneSpots[1].s, freq, grid);
    int ansN = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (ans1[i][j] < ans2[i][j]){
                ansN = 1;
                break;
            } if (ans2[i][j] < ans1[i][j]){
                ansN = 0;
                break;
            }
        }
        if (ansN != -1) break;
    }
    //only 2 and 2n have freq == 1
    if (ansN == 0) ans1 = ans2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            cout << ans1[i][j] << " ";
        }
        cout << ans1[i][n - 1];
        cout << "\n";
    }
}