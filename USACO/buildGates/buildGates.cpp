#include <bits/stdc++.h>
using namespace std;
int bigNum = 2005;
int n;
vector <vector <bool>> visited(bigNum, vector <bool> (bigNum, false));

void dfs(int i, int x){
    visited[i][x] = true;
    
    //cout << "i: " << i << " x: " << x << '\n';
    if (!visited[i + 1][x]) dfs(i + 1, x);
    if (!visited[i - 1][x]) dfs(i - 1, x);
    if (!visited[i][x + 1]) dfs(i, x + 1);
    if (!visited[i][x - 1]) dfs(i, x - 1);


}

void dfsIter(int i, int x){
    stack <pair <int, int>> s;
    s.push({i, x});
    while (!s.empty()){
        auto [i, x] = s.top();
        s.pop();
        
        visited[i][x] = true;

        if (!visited[i + 1][x]) s.push({i + 1, x});
        if (!visited[i - 1][x]) s.push({i - 1, x});
        if (!visited[i][x + 1]) s.push({i, x + 1});
        if (!visited[i][x - 1]) s.push({i, x - 1});
        
        
        
        
    }
}
int main(){
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int curI = bigNum/2, curX = bigNum/2;
    //cout << visited.size() << '\n';
    //cout << visited[0].size() << '\n';

    for (int i = 0; i < bigNum; i++){
        visited[i][0] = true; visited[i][bigNum - 1] = true;
    }
    fill(visited[0].begin(), visited[0].end(), true);
    fill(visited[bigNum - 1].begin(), visited[bigNum - 1].end(), true);

    cin >> n;
    visited[curI][curX] = true;

    for (int i = 0; i < n; i++){
        char tempCh;
        cin >> tempCh;
        if (tempCh == 'N'){
            visited[--curI][curX] = true;
            visited[--curI][curX] = true;
        }
        else if (tempCh == 'S'){
            visited[++curI][curX] = true;
            visited[++curI][curX] = true;
        }
        else if (tempCh == 'W'){
            visited[curI][--curX] = true;
            visited[curI][--curX] = true;
        }
        else if (tempCh == 'E'){
            visited[curI][++curX] = true;
            visited[curI][++curX] = true;
        }
    }
    int ans = 0;
    for (int i = 1; i < bigNum - 1; i++){
        for (int x = 1; x < bigNum - 1; x++){
            if (!visited[i][x]){
                //cout << i << " " << x << '\n';
                ans++;
                dfsIter(i, x);
            }
        }
    }
    cout << ans - 1;

}