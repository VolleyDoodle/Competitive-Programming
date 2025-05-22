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
        int n, q;
        cin >> n >> q;

        //a filled between [1..n]
        vector <int> a(n + 1), loc(n + 1);
        //locs[i] represents what index "i" is in a
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            loc[a[i]] = i;
        }
        for (int i = 0; i < q; i++){
            bool pos = true;
            int l, r, k, curAns = 0;
            cin >> l >> r >> k;
            int rhOpt = 0, lhOpt = 0;
            int lfCnt = n - k, rhCnt = k - 1;
            if (loc[k] < l || loc[k] > r){
                cout << -1 << " ";
                continue;
            }
            while (l <= r){
                int m = (l + r)/2;
                int pm = a[m];
                if (pm == k){
                    break;
                } else if (pm < k){
                    if (loc[k] < m){
                        if (lfCnt > 0){
                            rhOpt++;
                            curAns+=2;
                            lfCnt--;
                            r = m - 1;
                        } else{
                            pos = false;
                            break;
                        }
                    }
                    else if (loc[k] > m){
                        if (rhCnt > 0){
                            l = m + 1;
                            rhCnt--;
                        } else{
                            pos = false;
                            break;
                        }
                        
                    }
                    
                } else if (pm > k){
                    if (loc[k] > m){
                        if (rhCnt > 0){
                            lhOpt++;
                            curAns+=2;
                            rhCnt--;
                            l = m + 1;
                        } else{
                            pos = false;
                            break;
                        }
                    }
                    else if (loc[k] < m){
                        if (lfCnt > 0){
                            r = m - 1;
                            lfCnt--;
                        } else{
                            pos = false;
                            break;
                        } 
                    } 
                }
            }
            cout << (pos ? curAns - 2 * min(rhOpt, lhOpt) : -1) << " ";
        }
        cout << "\n";
    }
}