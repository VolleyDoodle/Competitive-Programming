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
        vector <pair <int, int>> lr(n);
        vector <int> suff_min(n + 1, 0), d(n);
        vector <int> adder(n, 0);
        suff_min[n] = INT_MAX;
        for (int i = 0; i < n; i++){
            cin >> d[i];
            if (i == 0) adder[i] = max(0, d[i]);
            else adder[i] = adder[i - 1] + max(d[i], 0);
        }
        for (int i = 0; i < n; i++){
            cin >> lr[i].f >> lr[i].s;
        }
        //al
        for (int i = n - 1; i >= 0; i--){
            suff_min[i] = min(suff_min[i + 1] , lr[i].s - adder[i]);
        }
        int curH = 0;
        bool pos = true;
        for (int i = 0; i < n; i++){
            //ith needs to go throgh lr[i] (which is included in suffmax)
            if (d[i] == -1){
                if (curH == suff_min[i]){
                    d[i] = 0;
                } else{
                    d[i] = 1;
                }
                curH += d[i];
            }
            if (curH + adder[i] < lr[i].f || curH + adder[i] > lr[i].s){
                pos = false;
            }
        }
        if (!pos){
            cout << -1 << "\n";
        } else{
            for (int i = 0; i < n; i++){
                cout << d[i] << " ";
            }
            cout << "\n";
        }
        

    }
}