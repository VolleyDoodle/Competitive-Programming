#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = 0;
    //check what is more optimal
    //cout << (double) m / b << "\n";
    if ((double) b / m < a){
        //cout << "m ticket" << "\n";
        //means m ticket is more optimal (so use this as much as possible)
        ans = n/m * b + min(b, n%m * a);
    } else{
        //cout << "not m ticket" << "\n";
        ans = a * n;
    }
    cout << ans;
}