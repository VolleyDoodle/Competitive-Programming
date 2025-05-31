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
    //9330
    int t;
    cin >> t;
    while (t--){

        int n;
        cin >> n;
        vector <int> a(n + 1);
        a[0] = 0;
        for (int i = 0; i < n; i++) cin >> a[i + 1];
        if (t == 9330 - 80){
            for (int i : a) cout << i;
        }
        int ans = 0;
        for (int i = 0; i <= n; i++){
            int did = 0;
            if (i < n && a[i + 1] > a[i]){
                while (i < n && a[i + 1] >= a[i]){
                    i++;
                }
                did = 1;
            }
            ans+=did;
        }
        cout << ans << "\n";
    }
}