#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector <vector <int>> grid(n + 2, vector <int>(m + 2, -1));
        map <int, int> colorCnt;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> grid[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (grid[i][j] == grid[i + 1][j] || grid[i][j] == grid[i - 1][j] 
                    || grid[i][j] == grid[i][j + 1] || grid[i][j] == grid[i][j - 1]){
                        colorCnt[grid[i][j]] = 2;
                    }
                else colorCnt[grid[i][j]] = max(colorCnt[grid[i][j]], 1);
            }
        }
        bool two = false;
        int ans = 0;
        for (auto& e : colorCnt){
            ans += e.s;
            if (e.s == 2) two = true;
        }
        if (colorCnt.size() == 1){
            cout << 0 << "\n";
            continue;
        }
        cout << (two ? ans - 2 : ans - 1) << "\n";
    }
}