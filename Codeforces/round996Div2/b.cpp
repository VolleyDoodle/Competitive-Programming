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
    int cnt = 0;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        if (a[i] < b[i]) cnt++;
    }
    //if more than two then impossible
    if (cnt > 1) {
        cout << "No";
        return;
    }
    //cnt == 0, or 1
    if (cnt == 0){
        cout << "Yes";
        return;
    }
    //cnt == 1
    int diff = 0;
    int minAway = INT_MAX;
    for (int i = 0; i < n; i++){
        if (a[i] < b[i]) diff = b[i] - a[i];
        else{
            minAway = min(minAway, a[i] - b[i]);
        }
    }
    if (minAway >= diff){
        cout << "Yes";
    } else{
        cout << "No";
    }
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