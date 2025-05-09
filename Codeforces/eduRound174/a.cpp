#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <int> b(n - 2);
        for (int i = 0; i < n - 2; i++){
            cin >> b[i];
        }
        bool pos = true;
        for (int i = 0; i < n - 4; i++){
            if (b[i] == 1 && b[i + 1] == 0 && b[i + 2] == 1) pos = false;
        }
        cout << (pos ? "YES" : "NO") << "\n";
    }
}