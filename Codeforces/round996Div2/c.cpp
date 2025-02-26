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
    int n, m;
    string st;
    cin >> n >> m;
    cin >> st;
    vector <vector <ll>> a(n, vector <ll>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int r = 0, c = 0;
    st+='D';
    for (char ch : st){
        ll tempSum = 0;
        if (ch == 'D'){
            for (int i = 0; i < m; i++){
                tempSum += a[r][i];
            }
            a[r][c] = -1 * tempSum;
            r++;
            
        } else{
            for (int i = 0; i < n; i++){
                tempSum += a[i][c];
            }
            a[r][c] = -1 * tempSum;
            c++;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
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
    }
}