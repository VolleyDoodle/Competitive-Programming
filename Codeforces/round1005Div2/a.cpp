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
        vector <int> shorten;
        int n;
        cin >> n;
        int cur = -1;
        for (int i = 0; i < n; i++){
            char c;
            cin >> c;
            int b = c - '0';
            if (b != cur){
                shorten.push_back(b);
                cur = b;
            }
        }
        if (shorten.size() == 1){
            if (shorten[0] == 0) cout << 0 << "\n";
            else cout << 1 << "\n";
            continue;
        } else{
            int ans = 0;
            if (shorten[shorten.size() - 1] == 1){
                ans++;
                shorten.pop_back();
            }
            for (int i = shorten.size() - 1; i >= 1; i-=2){
                ans+=2;
            }
            cout << ans << "\n";
        }
    }
}