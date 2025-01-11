#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, k, q;
    cin >> n >> k >> q;
    vector <vector <ll>> parallel(n, vector <ll>(k)), rowToCol(k, vector <ll>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            cin >> parallel[i][j];
            rowToCol[j][i] = parallel[i][j];
            if (i!=0) rowToCol[j][i]|=rowToCol[j][i - 1];
        }
    }
    for (int i = 0; i < q; i++){
        ll m;
        cin >> m;
        ll sOff = 0, eOff = n;
        bool impos = false;
        for (int x = 0; x < m; x++){
            ll r, c;
            char o;
            cin >> r >> o >> c;
            if (impos) continue;
            if (o == '<'){
                //in region r, less than c
                eOff = lower_bound(rowToCol[r - 1].begin() + sOff, rowToCol[r - 1].begin() + eOff, c) - rowToCol[r - 1].begin();
            } else{
                //in region r, more than c
                //auto it1 = upper_bound(rowToCol[r - 1].begin() + sOff, rowToCol[r - 1].begin() + eOff, c) - rowToCol[r - 1].begin();
                sOff = upper_bound(rowToCol[r - 1].begin() + sOff, rowToCol[r - 1].begin() + eOff, c) - rowToCol[r - 1].begin();
                
            }
            if (sOff >= eOff){
                impos = true;
                cout << -1;
            }
        }
        if (!impos){
            cout << sOff + 1;
        }
        cout << "\n";
    }

}