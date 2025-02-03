#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    string s;
    cin >> s;
    vector <vector <int>> pfs(s.size() + 1, {0, 0, 0});
    for (int i = 0; i < s.size(); i++){
        pfs[i + 1] = pfs[i];
        if (s[i] == 'C'){
            pfs[i + 1][0]++;
        } else if (s[i] == 'O'){
            pfs[i + 1][1]++;
        } else{
            pfs[i + 1][2]++;
        }
    }
    int q;
    cin >> q;
    string ans = "";
    while (q--){
        int l, r;
        cin >> l >> r;
        int cCount = pfs[r][0] - pfs[l - 1][0];
        int oCount = pfs[r][1] - pfs[l - 1][1];
        int wCount = pfs[r][2] - pfs[l - 1][2];
        cCount%=2; oCount%=2; wCount%=2;

        if (wCount == oCount){
            ans += ((cCount + oCount)%2 == 1 ? 'Y' : 'N');
        } else{
            ans += 'N';
        }
    }
    cout << ans;
}