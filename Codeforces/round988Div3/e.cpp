#include <bits/stdc++.h>
#define ll long long
#define s second
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n;
    cin >> n;
    bool pos = false;
    vector <int> ans(n + 2, -1);
    int askBefore = -1;
    for (int i = 2; i <= n; i++){
        cout << "? 1 " << i << "\n";
        cout.flush();
        int f;
        cin >> f;
        if (f > 0){
            pos = true;
            for (int x = 1; x < (i - f); x++){
                ans[x] = 1;
            } for (int x = i - f; x < i; x++){
                ans[x] = 0;
            }
            ans[i] = 1;
            askBefore = f;
            break;
        } 
    }
    if (!pos){
        cout << "! IMPOSSIBLE";
        cout.flush();
        return;
    }
    int last;
    for (int i = n; i >= 1; i--){
        if (ans[i] >= 0){
            if (last == askBefore){
                ans[i + 1] = 0;
            } else{
                ans[i + 1] = 1;
            }
            break;
        }
        cout << "? 1 " << i << "\n";
        cout.flush();
        int f;
        cin >> f;
        if (i == n){
            last = f;
            continue;
        }
        if (last == f){
            ans[i + 1] = 0;
            last = f;
        } else if (last > f){
            ans[i + 1] = 1;
            last = f;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++){
        cout << ans[i];
    }
    cout.flush();
    
    
}
int main(){
    /*ios::sync_with_stdio(false);
    cin.tie(nullptr);*/
    setIO("txt");
    //cout << "hi";
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}