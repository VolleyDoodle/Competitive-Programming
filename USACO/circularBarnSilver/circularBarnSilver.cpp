#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
vector <int> rooms;
void solve(int needCow){
    //needCow is room that has no cows
    int curCow = needCow, doors = 0;
    while (true){
        
        if (rooms[curCow]){
            rooms[curCow]--;
            rooms[needCow]++;
            ans += doors * doors;
            break;
        }
        curCow--;
        if (!curCow){curCow = n;}
        
        doors++;
    }
}
int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rooms.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> rooms[i];
    }   
    int curCow = n; 
    while (true){
        if (!rooms[curCow]){
            solve(curCow);
        }
        bool allEqual = true;
        for (int i = 1; i <= n; i++){
            if (!rooms[i]){allEqual = false;}
        }
        if (allEqual){break;}
        curCow--;
        if (!curCow){ curCow = n;}
    }
    cout << ans;
}