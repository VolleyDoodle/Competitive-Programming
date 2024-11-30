#include <bits/stdc++.h>
using namespace std;
vector <vector <bool>> fields, visited;
set <vector <int>> weights;
int cowsVisited, n;
//above map basically stores roads between fields
void floodfill(int x, int y){
    if (x == 0 || x == n + 1 || y == 0 || y == n + 1){
        return;
    }
    if (fields[x][y]){
        cowsVisited++;
    }
    visited[x][y] = true;
    if (!weights.count({x, y, x + 1, y}) && !visited[x + 1][y]){
        floodfill(x + 1, y);
    } if (!weights.count({x, y, x, y + 1}) && !visited[x][y + 1]){
        floodfill(x, y + 1);
    } if (!weights.count({x, y, x - 1, y}) && !visited[x - 1][y]){
        floodfill(x - 1, y);
    } if (!weights.count({x, y, x, y - 1}) && !visited[x][y - 1]){
        floodfill(x, y - 1);
    }
    //if (weights[])
}
int main(){
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int  k, r, ans = 0;
    cin >> n >> k >> r;
    fields.resize(n + 2); visited.resize(n + 2);
    for (int i = 0; i < n + 2; i++){
        fields[i].resize(n + 2); fill(fields[i].begin(), fields[i].end(), 0);
        visited[i].resize(n + 2);
    }
    for (int i = 0; i < r; i++){
        int tr, tc, tx, ty;
        cin >> tc >> tr >> ty >> tx;
        //vector <int> tempV = {tr, tc, tx, ty};
        weights.insert({tr, tc, tx, ty});
        weights.insert({tx, ty, tr, tc});
    }
    for (int i = 0; i < k; i++){
        int cx, cy;
        cin >> cy >> cx;
        fields[cx][cy] = true;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (fields[i][j]){
                cowsVisited = 0;
                for (int x = 0; x < n; x++) fill(visited[x].begin(), visited[x].end(), 0);
                floodfill(i, j);
                ans+= k - cowsVisited;
            }
        }
    }
    /*for (auto element : weights){
        for (int e : element.first){
            cout << e << " ";
        }
        cout << "\n";
    }*/
    
    cout << ans/2;
}