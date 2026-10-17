#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string pre){
    freopen((pre + ".in").c_str(), "r", stdin);
    freopen((pre + ".out").c_str(), "w", stdout);
}

void solve(){
    int n;
    cin >> n;
    //smthn with halves and shit
    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int cur_least = 10e9 + 1;
    bool pos = 1;
    for (int i = 0; i < n; i++){
        cur_least = min(cur_least, nums[i]);
        if (cur_least <= (nums[i] / 2)){
            pos = 0;
        }
    }
    cout << (pos ? "YES": "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}