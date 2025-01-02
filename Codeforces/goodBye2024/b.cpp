#include <bits/stdc++.h>
using namespace std;
#define f first 
#define s second
void solve(){
    int n;
    cin >> n;
    vector <int> cnt(2 * n + 1, 0);
    vector <pair <int ,int>> lr(n);
    for (int i = 0; i < n; i++){
        cin >> lr[i].f >> lr[i].s;
        if (lr[i].f == lr[i].s) cnt[lr[i].f]++;
    }
    //ok so now, basically it is only a "segment" when the cnt is like
    //1, 1, 1, 1, 1
    //or could be like 1, 2, 3, 1, 1, 2, but the point is that the value is > 0 and consecutive
    vector <int> pfs(2 * n + 1, 0);
    /*for (int i = 0; i < 2 * n; i++){
        pfs[i + 1] = pfs[i] + bool(cnt[i + 1]);
    }*/
    //above way basically icnrements by one for every continuous segment
    //below is different way (jiangly + andrew he person did)
    for (int i = 0; i < 2 * n; i++){
        pfs[i + 1] = pfs[i] + !bool(cnt[i + 1]);
    }
    //stores continues lengths of visited
    //commented out code works as well!
    for (int i = 0; i < n; i++){
        if (lr[i].f == lr[i].s){
            cout << (cnt[lr[i].f] == 1 ? '1' : '0');
        } else{
            //cout << (pfs[lr[i].s] - pfs[lr[i].f - 1] == lr[i].s - lr[i].f + 1  ? '0' : '1');
            cout << (pfs[lr[i].s] == pfs[lr[i].f - 1] ? '0' : '1');
        }
    }

}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}