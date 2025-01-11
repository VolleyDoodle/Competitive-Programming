#include <bits/stdc++.h>
using namespace std;


int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int n;
    cin >> n;
    vector <vector <int>> inputs(n);
    for (int i = 0; i < n; i++){
        for (int x = 0; x < n - i; x++){
            int t;
            cin >> t;
            inputs[i].push_back(t);
        }
    }
    vector <int> ans(n);
    ans[0] = 0;
    int totMax = 0, totMin = 0;
    for (int i = 1; i < n; i++){
        //either it is r + curMax
        //or r - curMin
        //so try both cases and see which one works
        int r = inputs[i-1][1];
        bool okPos = true, okNeg = true;
        for (int x = 0; x < i; x++){
            //currently looking at inputs[x][i-x]
            int curMax = ans[x], curMin = ans[x];
            for (int j = x; j < i; j++){
                curMax = max(curMax, ans[j]);
                curMin = min(curMin, ans[j]);
            }
            //ok now we have the min and max for the query inputs[x][i - x]
            if (max(curMax, ans[i - 1] + r) - curMin != inputs[x][i-x]){
                okPos = false;
            } if (curMax - min(curMin, (ans[i - 1] - r)) != inputs[x][i-x]){
                okNeg = false;
            }
        }
        if (okPos) ans[i] = ans[i - 1] + r;
        if (okNeg) ans[i] = ans[i - 1] - r;
        totMax = max(totMax, ans[i]);
        totMin = min(totMin, ans[i]);
    }
    for (int i = 0; i < n; i++){
        cout << ans[i];
        if (i != n - 1) cout << " ";
    }
}