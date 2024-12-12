#include <bits/stdc++.h>
using namespace std;
bool suc = false;
void brute(int twos, int threes, int sum){
    if (twos < 0 || threes < 0) return;
    if (sum%9 == 0){
        suc = true;
    }
    brute(twos - 1, threes, (sum + 2)%9);
    brute(twos, threes - 1,(sum + 6)%9);
}
void solve(){
    string s;
    cin >> s;

    int amt2 = 0, amt3 = 0;
    int sum = 0;
    for (char ch : s){
        int tNum = ch - '0';
        if (tNum == 2) amt2++;
        if (tNum == 3) amt3++;
        sum += tNum%9;
    }
    suc = false;
    sum%=9;
    brute(min(9, amt2), min(3, amt3), sum);
    if (suc) cout << "YES";
    else cout << "NO";
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}