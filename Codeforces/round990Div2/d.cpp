#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    priority_queue <pair <int ,int>, vector <pair <int, int>>, greater <pair <int, int>>> values;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        values.push({a, i});
    }
    int curMinIdx = 0;
    while (!values.empty()){
        auto curVal = values.top();
        if (curVal.second < curMinIdx){
            values.pop();
            values.push({curVal.first + 1, n});
        } else{
            curMinIdx = curVal.second;
            cout << curVal.first << " ";
            values.pop();
        }
    }

}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}