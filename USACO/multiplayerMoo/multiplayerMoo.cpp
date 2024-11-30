#include <bits/stdc++.h>

using namespace std;
int elementsNum = 0, ans = 0;
vector <vector <int>> score(6, vector <int>(6, 0));
vector <vector <bool>> visited(6, vector <bool>(6, false));
vector <vector <bool>> checked(6, vector <bool>(6, false));
vector <vector <int>> grid(6, vector<int>(6, -1));
map <int, int> storedVal;
void dfs(int i,int x){
    visited[i][x] = true;
    elementsNum++;
    if (grid[i][x] == grid[i + 1][x] && !visited[i + 1][x]) dfs(i + 1, x);
    if (grid[i][x] == grid[i - 1][x] && !visited[i - 1][x]) dfs(i - 1, x);
    if (grid[i][x] == grid[i][x + 1] && !visited[i][x + 1]) dfs(i, x + 1);
    if (grid[i][x] == grid[i][x - 1] && !visited[i][x - 1]) dfs(i, x - 1);
}
void fillScore(int i, int x){
    score[i][x] = elementsNum;
    visited[i][x] = false;
    if (visited[i + 1][x]) fillScore(i + 1, x);
    if (visited[i - 1][x]) fillScore(i - 1, x);
    if (visited[i][x + 1]) fillScore(i, x + 1);
    if (visited[i][x - 1]) fillScore(i, x - 1);

}

void calcSolve(int i, int x){
    visited[i][x] = true;
    if (grid[i][x] == grid[i + 1][x] && !visited[i + 1][x]) calcSolve(i + 1, x);
    if (grid[i][x] == grid[i - 1][x] && !visited[i - 1][x]) calcSolve(i - 1, x);
    if (grid[i][x] == grid[i][x + 1] && !visited[i][x + 1]) calcSolve(i, x + 1);
    if (grid[i][x] == grid[i][x - 1] && !visited[i][x - 1]) calcSolve(i, x - 1);

    if (grid[i][x] != grid[i + 1][x] && grid[i + 1][x] != -1 && !checked[i + 1][x]){
        storedVal[grid[i + 1][x]]+=score[i + 1][x];
        ans = max(ans, score[i][x] + storedVal[grid[i + 1][x]]);
        checked[i + 1][x] = true;
    }
    if (grid[i][x] != grid[i - 1][x] && grid[i - 1][x] != -1 && !checked[i - 1][x]){
        storedVal[grid[i - 1][x]]+=score[i - 1][x];
        ans = max(ans, score[i][x] + storedVal[grid[i - 1][x]]);
        checked[i - 1][x] = true;
    }
    if (grid[i][x] != grid[i][x + 1] && grid[i][x + 1] != -1 && !checked[i][x + 1]){
        storedVal[grid[i][x + 1]]+=score[i][x + 1];
        ans = max(ans, score[i][x] + storedVal[grid[i][x + 1]]);
        checked[i][x + 1] = true;
    }
    if (grid[i][x] != grid[i][x - 1] && grid[i][x - 1] != -1 && !checked[i][x - 1]){
        storedVal[grid[i][x - 1]]+=score[i][x - 1];
        ans = max(ans, score[i][x] + storedVal[grid[i][x - 1]]);
        checked[i][x - 1] = true;
    }
}
int main(){
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    int n;
    cin >> n;
    

    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= n; x++){
            cin >> grid[i][x];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= n; x++){
            if (!visited[i][x]){
                elementsNum = 0;
                dfs(i , x);
                ans = max(ans, elementsNum);
                fillScore(i, x);
            }
        }
    }
    cout << ans << '\n';
    ans = 0;
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= n; x++){
            if (!visited[i][x]){
                storedVal.clear();
                calcSolve(i, x);
                for (int y = 1; y <= n; y++){
                    fill(checked[y].begin(), checked[y].end(), false);
                }
            }
        }
    }

    cout << ans;
}