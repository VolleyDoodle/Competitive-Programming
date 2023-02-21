#include <bits/stdc++.h>
using namespace std;
int visited[1002][1002];
bool grid[1002][1002];
int areaAns = -1, periAns = -1;
int curAreaAns, curPeriAns;
void fill(int i, int x){
    visited[i][x] = true;
    curAreaAns++;
    int tPeri = 4;
    if (grid[i + 1][x]){
        tPeri--;
        if (!visited[i + 1][x]){
            fill(i + 1, x);
        }
    } if (grid[i - 1][x]){
        tPeri--;
        if (!visited[i - 1][x]){
            fill(i - 1, x);
        }   
    } if (grid[i][x + 1]){
        tPeri--;
        if (!visited[i][x + 1]){
            fill(i, x + 1);
        }
    } if (grid[i][x - 1]){
        tPeri--;
        if (!visited[i][x - 1]){
            fill(i, x - 1);
        }
        
    }
    curPeriAns +=tPeri;
}
int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= n; x++){
            char t; cin >> t;
            if (t == '#'){grid[i][x] = true;}
        }
    }
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= n; x++){
            if (grid[i][x] && !visited[i][x]){
                curAreaAns = 0; curPeriAns = 0;
                fill(i, x);
                if (curAreaAns == areaAns && curPeriAns < periAns){
                    areaAns = curAreaAns; periAns = curPeriAns;
                } else if( curAreaAns > areaAns){
                    areaAns = curAreaAns; periAns = curPeriAns;;
                }
            }
        }
    }
    cout << areaAns << " " << periAns;

}