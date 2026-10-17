#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
int dist(pair <int, int> p1, pair <int, int> p2){
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("checklist");
    int H, G;
    cin >> H >> G;
    //okay, what an interesting problem
    //so we KNOW that we start at Holstein 1 and end at Holstein H
    //
    vector <pair <int, int>> hol(H), gue(G + 1);
    for (int i = 0; i < H; i++) cin >> hol[i].first >> hol[i].second;
    gue[0].first = hol[0].first;
    gue[0].second = hol[0].second;
    for (int i = 1; i <= G; i++) cin >> gue[i].first >> gue[i].second;


    //Holstein I can come from either Holstein i - 1, or any of the Guernseys
    //but what abt the Guerneyseysss?
    
    //dp[i][j], let that be first i holsteins, first j guenryes, ending with ith holstein
    vector <vector <int>> dp1(H + 1, vector <int>(G + 1, 1e9));
    //dp[i][j], ending with ith guersey
    vector <vector <int>> dp2(G + 1, vector <int>(H + 1, 1e9));
    //okay, lets first assume that 
    dp1[1][0] = 0;
    for (int i = 1; i <= H; i++){
        //ith holsteins
        //which is referecned to i - 1 in the array
        for (int j = 0; j <= G; j++){
            //jth guernssey (just j) in array
            //dp1[i][j]
            //always from i - 1 holstein, but either that can be at the front, or some j guenrsey
            //
            if (i > 1) dp1[i][j] = dp1[i - 1][j] + dist(hol[i - 1], hol[i - 2]);
            dp1[i][j] = min(dp1[i][j], dp2[j][i - 1] + dist(gue[j], hol[i - 1]));

            //dp2[i][j]
            if (j > 0) dp2[j][i] = dp2[j - 1][i] + dist(gue[j], gue[j - 1]);
            if (j > 0) dp2[j][i] = min(dp2[j][i], dp1[i][j - 1] + dist(gue[j], hol[i - 1]));
        }
    }
    //
    cout << dp1[H][G];
}