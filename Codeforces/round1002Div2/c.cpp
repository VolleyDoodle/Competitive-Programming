#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector <int> cnts;
    for (int i = 0; i < n; i++){
        int curCnt = 0;
        for (int j = n - 1; j >= 0; j--){
            if (a[i][j] == 1){
                curCnt++;
            } else{
                break;
            }
        }
        cnts.push_back(curCnt);
    }
    sort(cnts.begin(), cnts.end());
    int curMex = 0;
    for (int cnt : cnts){
        if (cnt >= curMex){
            curMex++;
        }
    }
    cout << curMex;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}