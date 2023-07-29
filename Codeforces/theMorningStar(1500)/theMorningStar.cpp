#include <bits/stdc++.h>
using namespace std;

void solve(){
    //freopen("output.out", "w", stdout);dds
    map <int, int> xValues, yValues, slopeValPos, slopeValNeg;
    vector <pair <int, int>> cords;
    int n; long long ans = 0;
    cin >> n;
    int tX, tY;
    for (int i = 0; i < n; i++){
        
        cin >> tX >> tY;
        cords.push_back({tX, tY});
        xValues[tX]++; yValues[tY]++;
        slopeValPos[tY - tX]++; slopeValNeg[tY + tX]++;
    }
    for (pair <int, int> e : cords){
        tX = e.first; tY = e.second;
        ans+=xValues[tX] - 1; ans+=yValues[tY] - 1;
        ans+=slopeValPos[tY - tX] - 1; ans+=slopeValNeg[tY + tX] - 1;
    }
    cout <<  ans << "\n";

}
int main(){
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}