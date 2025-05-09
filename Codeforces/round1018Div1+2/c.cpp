#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
ll solve(vector <vector <int>>& h, vector <int>& a){
    int n = a.size();
    vector <vector <ll>> dp(n + 1, vector <ll>(2, 1e18));
    dp[0][0] = 0; dp[0][1] = a[0];
    for (int i = 1; i < n; i++){
        for (int x = 0; x < 2; x++){
            //this is ith row, x represents using row operation
            for (int y = 0; y < 2; y++){
                //this is for i - 1th row, y represents if used?
                bool good = true;
                for (int j = 0; j < n; j++){
                    if (h[i][j] + x == h[i - 1][j] + y){
                        good = false;
                    }
                }
                if (good){
                    dp[i][x] = min(dp[i][x], dp[i - 1][y] + (x == 1 ? a[i] : 0));
                }
            }
            
        }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);

}
void transpose(int n, vector<vector<int>>& h) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(h[i][j], h[j][i]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int t;

    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <vector <int>> h(n, vector <int>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> h[i][j];
            }
        }
        vector <int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        ll max = solve(h, a);
        //cout << "vert max: " << max << "\n";
        transpose(n, h);
        ll horizCost = solve(h, b);
        //cout << "horiz cost: " << horizCost << "\n";
        max+=horizCost;
        if (max >= 1e18){
            cout << -1 << "\n";
            continue;
        }
        cout << max << "\n";
    }
    

}