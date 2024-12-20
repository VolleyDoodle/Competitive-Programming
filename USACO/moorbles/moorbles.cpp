#include <bits/stdc++.h>
using namespace std;
//Even Even Even Even Even Even Even Even Even Even Even Even Odd Even Even Odd
//Even Even Even Even Even Even Even Even Odd Even Even Even Even Even Even Even
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
    vector <long long> amtLeft(m + 1, 0), pfsDip(m + 1, 0), curDip(m + 1);
    vector <int> curAns(m);
    for (int i = m - 1; i >= 0; i--){
        //pfsDip[i] = pfsDip[i + 1];
        amtLeft[i] = amtLeft[i + 1];
        if (cards[i][0]%2 != cards[i][1]%2){
            amtLeft[i]-=min(cards[i][0], cards[i][1]);
            curAns[i] = max(cards[i][0], cards[i][1])%2;
        } else{
            amtLeft[i]+=min(cards[i][0], cards[i][1]);
            curAns[i] = cards[i][0]%2;
        }
        curDip[i] = amtLeft[i] - amtLeft[i + 1];
        //pfsDip[i] = min(pfsDip[i], amtLeft[i] - amtLeft[i + 1]);
    }
    vector <long long> biggestDip(m + 1, 0);
    for (int i = 1; i < m + 1; i++){
        pfsDip[i] = pfsDip[i - 1];
        pfsDip[i]+=curDip[i - 1];
        
    }
    for (int i = m; i >= 1; i--){
        if (i == m){
            biggestDip[i] = pfsDip[i];
            continue;
        }
        biggestDip[i] = min(pfsDip[i], biggestDip[i + 1]);
    }
    long long keepTrack = 0;
    for (int i = 0; i < m; i++){
        //nothing can change to sequence if below is true
        if (n + (amtLeft[0] - amtLeft[i + 1]) <= 0){
            cout << -1; return;
        }
        if (curAns[i] == 0){
            if (cards[i][0]%2 != cards[i][1]%2){
                keepTrack+=cards[i][1];
            } else{
                keepTrack-=min(cards[i][0],cards[i][1]);
            }
            continue;
        }
        //so only when curAns == 1 is when we want to see if can switch
        //two cases
        //first case, one odd and one even, try to see if possible to take even
        if (cards[i][0]%2 != cards[i][1]%2){
            //diff+= cards[i][1] - cards[i][0];
            
            keepTrack += cards[i][1];
            if ((n - keepTrack) + amtLeft[i + 1] > 0 && n - keepTrack > 0 && (n - keepTrack) + biggestDip[i + 1] - pfsDip[i + 1] > 0){
                curAns[i] = 0;
            } else{
                keepTrack-=cards[i][1];
                keepTrack+=cards[i][0];
            }
        } else{
            keepTrack+= max(cards[i][0], cards[i][1]);
            if ((n - keepTrack) + amtLeft[i + 1] > 0 && n - keepTrack > 0 && (n - keepTrack) + biggestDip[i + 1] - pfsDip[i + 1] > 0 ){
                curAns[i] = 0;
            } else{
                keepTrack-=max(cards[i][0], cards[i][1]);
                keepTrack-=min(cards[i][0], cards[i][1]);
            }
        }
        
        //second case, two odds, and then try to tank the biggest odd
    }
    for (int i = 0; i < curAns.size() - 1; i++){
        if (curAns[i] == 1){
            cout << "Odd ";
        }
        else{
            cout << "Even ";
        }
    }
    cout << (curAns[curAns.size() - 1] == 1 ? "Odd" : "Even");
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