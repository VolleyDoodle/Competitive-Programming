#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vector <int> cows(n);
    for (int i = 0; i < n; i++){
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    
}