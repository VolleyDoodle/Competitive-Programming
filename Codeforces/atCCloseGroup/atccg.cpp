#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int n, m;
    cin >> n >> m;
    vector <int> graph(n + 1, 0);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a] = (graph[a] | 1 << (b - 1));
        graph[b] = (graph[b] | 1 << (a - 1));
    }
    //precompute
    vector <int> dp(1 << n, 18);
    //naively O(2^n * n^2) <- js looping through all subsets then brute-forcing check
    //O(2^n * n) exists ? what is it tho? 
    dp[0] = 1;
    for (int s = 1; s < (1 << n); s++){
        int subset = s & (s - 1);
        

        if (dp[subset] == 18) continue;
        int val = s & (-s);
        val = log2(val) + 1;
        bool connect = true;

        for (int i = 0; i <= n; i++){
            if (((1 << i) & subset) && ((graph[val] & (1 << i)) == 0)){
                connect = false;
            }
        }
        if (connect) dp[s] = dp[subset];
    }
    /*for (int i = 0; i < (1 << n); i++){
        if (dp[i] == 18) continue;
        cout << "i: " << i << ": " << dp[i] << "\n";
    }*/

    for (int s = 0; s < (1 << n); s++){
        for (int subset = s; subset != 0; subset = (subset - 1) & s){
            int other = s ^ subset;
            dp[s] = min(dp[s], dp[subset] + dp[other]);
        }
    }
    cout << dp[(1 << n) - 1];
}