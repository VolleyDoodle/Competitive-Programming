#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> rooms, dScore;
//stores #of cows and current d-score (only if =1)
void giveAndGo(int i){
    int d = 0;
    while (rooms[(i + d)%n] == 0){
        d++;
    }
    rooms[(i + d)%n]--;
    rooms[i]++;
    dScore[i] = d + dScore[(i + d)%n];
    //return (d * d) - (dScore[(i + d)%n] * dScore[(i + d)%n]);
}
int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;   
    rooms.resize(n);
    dScore.resize(n);
    fill(dScore.begin(), dScore.end(), 0);
    for (int i = 0; i < n; i++){
        cin >> rooms[i];
    } 
    int ans = 0;
    reverse(rooms.begin(), rooms.end());
    auto it = find(rooms.begin(), rooms.end(), 0);
    int index = it - rooms.begin();
    while (it != rooms.end()){
        giveAndGo(it - rooms.begin());
        //if (rooms[index%n] == 0) ans+=giveAndGo(index%n);
        //index++;
        it = find(rooms.begin(), rooms.end(), 0);

    }
    for (int i = 0; i < n; i++){
        ans+= (dScore[i] * dScore[i]);
    }
    
    cout << ans;
}