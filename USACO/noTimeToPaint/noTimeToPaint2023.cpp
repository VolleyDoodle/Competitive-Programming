#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, q;
    string fence;
    cin >> n >> q;
    cin >> fence;
    vector <vector <int>> pfsum(n + 1);
    for (int i = 0; i <= n; i++){
        pfsum[i].resize(26);
        fill(pfsum[i].begin(), pfsum[i].end(), 0);
    }
    char curMin = '(', cur = '.';
    for (int i = 1; i <= n; i++){
        if (i == 1) {
            pfsum[i][fence[i - 1] - 65]++;
            curMin = fence[i - 1]; cur = fence[i - 1];
            continue;
        }
        pfsum[i] = pfsum[i - 1];
        if (fence[i - 1] > curMin && fence[i - 1] != cur){
            pfsum[i][fence[i - 1] - 65]++;
        } else{
            curMin = fence[i - 1];
        }
        cur = fence[i - 1];
    }
    
    while(q--){
        int start, end;
        cin >> start >> end;
        int ans = 0;
        for (int i = 0; i < 26; i++){
            ans+=pfsum[start - 1][i] - pfsum[0][i];
            ans+=pfsum[n][i] - pfsum[end][i];
        }
        cout << ans + 1 << '\n';
    }
}