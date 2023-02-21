#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector <pair <int, int>> x_y(n), y_x(n);
    //basically only 4 cows matter bx,by, tx, ty (t = top, b = bottom)
    for (int i = 0; i < n; i++){
        cin >> x_y[i].first >> x_y[i].second;
        y_x[i].first = x_y[i].second; y_x[i].second = x_y[i].first;
    }
    sort(x_y.begin(), x_y.end());
    sort(y_x.begin(), y_x.end());
    //4^4
    for (int i = 0; i < 4; i++){
        
    }
}