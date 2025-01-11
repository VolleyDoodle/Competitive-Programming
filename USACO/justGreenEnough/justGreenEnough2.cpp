#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll oneD(vector <int>& v){
    ll oneCount = 0, tAns = 0;
    for (int i = 0; i < v.size(); i++){
        if (v[i] == 1) oneCount++;
        else{
            tAns += (oneCount + 1) * (oneCount)/2;
            oneCount = 0;
        }
    }
    tAns += (oneCount + 1) * (oneCount)/2;
    return tAns;
}
ll calc(int m, vector<vector<ll>> grid ){
    ll curAns = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            grid[i][j] = (grid[i][j] >= m ? 1 : -1e8);
            grid[i][j] += grid[i][j - 1];
        }
    }
    for (int w = 1; w <= n; w++){
        //this is the width of the subgrid we are looking at
        for (int j = 1; j <= n - w + 1; j++){
            vector <int> v;
            for (int i = 1; i <= n; i++){
                if (grid[i][j + w - 1] - grid[i][j - 1] > 0){
                    v.push_back(1);
                } else v.push_back(0);
            }
            curAns+=oneD(v);
        }
    }
    return curAns;

}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);

    cin >> n;
    vector <vector <ll>> grid(n + 1, vector <ll>(n + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    ll ans1 = calc(100, grid);
    ll ans2 = calc(101, grid);
    
    cout << ans1 - ans2;
    //O(n^3)
    //in grid.. <100 = -1e8, ==100 = 1, > 100 = 0

}