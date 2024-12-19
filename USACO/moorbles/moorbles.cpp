#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> cards(m, vector <int>(2, 0));
    for (int i = 0; i < m; i++){
        vector <int> pos(k);
        for (int x = 0; x < k; x++){
            cin >> pos[x];
        }
        sort(pos.begin(), pos.end());
        for (int x = 0; x < k; x++){
            cards[i][pos[x]%2] = pos[x];
        }

        if (cards[i][0] == 0){
            //all potential moves are odd
            for (int x = pos.size() - 1; x >= 0; x--){
                cards[i][0] = pos[x];
            }
        } else if (cards[i][1] == 0){
            //all potential moves are even
            for (int x = pos.size() - 1; x >= 0; x--){
                cards[i][1] = pos[x];
            }
        }
    }
    //now build the sequence with the greatest amount remaing from i..m
    vector <long long> amtLeft(m + 1, 0);
    vector <int> curAns(m);
    for (int i = m - 1; i >= 0; i--){
        amtLeft[i] = amtLeft[i + 1];
        if (cards[i][0]%2 != cards[i][1]%2){
            amtLeft[i]-=min(cards[i][0], cards[i][1]);
            curAns[i] = max(cards[i][0], cards[i][1])%2;
        } else{
            amtLeft[i]+=min(cards[i][0], cards[i][1]);
            curAns[i] = cards[i][0]%2;
        }
    }
    if (n + amtLeft[0] <= 0){
        cout << -1; return;
    }
    long long diff = 0;
    for (int i = 0; i < m; i++){
        //nothing can change to sequence if below is true
        if (curAns[i] == 0) continue;
        //so only when curAns == 1 is when we want to see if can switch
        //two cases
        //first case, one odd and one even, try to see if possible to take even
        if (cards[i][0]%2 != cards[i][1]%2){
            diff+= cards[i][1] - cards[i][0];
            if (n + (amtLeft[i] - diff) > 0){
                curAns[i] = 0;
            } else{
                diff-=cards[i][1] - cards[i][0];
            }
        } else{
            diff+=max(cards[i][0], cards[i][1]) + min(cards[i][0], cards[i][1]);
            if (n + (amtLeft[i] - diff) > 0){
                curAns[i] = 0;
            } else{
                diff-=max(cards[i][0], cards[i][1]) + min(cards[i][0], cards[i][1]);
            }
        }
        
        //second case, two odds, and then try to tank the biggest odd
    }
    for (int i: curAns){
        if (i == 1){
            cout << "Odd ";
        }
        else{
            cout << "Even ";
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