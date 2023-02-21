#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector <string> strs(n);
    for (int i = 0; i < n; i++){
        cin >> strs[i];
    }
    sort(strs.begin(), strs.end());
    for (int i = 0; i < n; i++){
        cout << strs[i] << "\n";
    }
    cout << "\n";
}