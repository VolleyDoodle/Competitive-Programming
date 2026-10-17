#include <bits/stdc++.h>
#define ll long long

using namespace std;


void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int maxSwaps = 435;

    string s;
    cin >> s;

    int k;
    cin >> k;

    vector <int> cnt(3, 0);
    vector <vector <int>> pos(3);
    map <char, int> idx;
    idx['K'] = 0; idx['E'] = 1; idx['Y'] = 2;

    for (int i = 0; i < s.size(); i++){
        cnt[idx[s[i]]]++;
        pos[idx[s[i]]].push_back(i);
    }
    //what an insane problem? how is this "normal" difficulty?
    //invesion counting + dp
    //idk don't feel like explaining
    //lets say dp[k][e][y][cost]
    //k = # of ks used
    //e = # of es used
    //y = # of ys used
    //cost = cost (calculated using inversion counting) sounds fancy but very simple
    static ll dp[31][31][31][436];
    ll ans = 0;
    dp[0][0][0][0] = 1;
    for (int kc = 0; kc <= cnt[0]; kc++){
        for (int ke = 0; ke <= cnt[1]; ke++){
            for (int ky = 0; ky <= cnt[2]; ky++){
                for (int cost = 0; cost <= maxSwaps; cost++){
                    if (kc < cnt[0]){
                        //inversion countin ahh
                        //say you have KE -> EK basically indices i, j went to j, i
                        //if kc = 0, that means we are adding from pos[0][kc]
                        int beforeCnt = kc + 
                        (upper_bound(pos[1].begin(), pos[1].begin() + ke, pos[0][kc]) - pos[1].begin())
                        + (upper_bound(pos[2].begin(), pos[2].begin() + ky, pos[0][kc]) - pos[2].begin());
                        int afterCnt = (kc + ke + ky) - beforeCnt;
                        dp[kc + 1][ke][ky][cost + afterCnt] += dp[kc][ke][ky][cost];
                    }
                    if (ke < cnt[1]){
                        //inversion countin ahh
                        //say you have KE -> EK basically indices i, j went to j, i
                        //if kc = 0, that means we are adding from pos[0][kc]
                        int beforeCnt = ke + 
                        (upper_bound(pos[0].begin(), pos[0].begin() + kc, pos[1][ke]) - pos[0].begin())
                        + (upper_bound(pos[2].begin(), pos[2].begin() + ky, pos[1][ke]) - pos[2].begin());
                        int afterCnt = (kc + ke + ky) - beforeCnt;
                        dp[kc][ke + 1][ky][cost + afterCnt] += dp[kc][ke][ky][cost];
                    }
                    if (ky < cnt[2]){
                        //inversion countin ahh
                        //say you have KE -> EK basically indices i, j went to j, i
                        //if kc = 0, that means we are adding from pos[0][kc]
                        int beforeCnt = ky + 
                        (upper_bound(pos[0].begin(), pos[0].begin() + kc, pos[2][ky]) - pos[0].begin())
                        + (upper_bound(pos[1].begin(), pos[1].begin() + ke, pos[2][ky]) - pos[1].begin());
                        int afterCnt = (kc + ke + ky) - beforeCnt;
                        dp[kc][ke][ky + 1][cost + afterCnt] += dp[kc][ke][ky][cost];
                    }
                    if (kc == cnt[0] && ke == cnt[1] && ky == cnt[2] && cost <= k){
                        ans += dp[kc][ke][ky][cost];
                    }
                }
            }
        }
    }
    cout << ans;

}