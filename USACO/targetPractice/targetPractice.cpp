#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t, c;
    cin >> t >> c;
    vector <bool> targets(2 * c + 2);
    for (int i = 0; i < t; i++){
        int t1;
        cin >> t1; t1+=c;
        targets[c] = true;
    }
    string s; cin >> s;
    int curLoc = c;
    vector <pair<int, int>> fireLoc;
    for (int i = 0; i < c; i++){
        if (s[i] == 'L'){
            curLoc--;
        }
        else if (s[i] == 'R'){
            curLoc++;
        }
        else{
            int countF = 0;
            while (s[i] == 'F'){
                countF++;
                i++;
            }
            i--;
            fireLoc.push_back({curLoc, countF});
        }
    }
    vector <int> shiftRight, shiftLeft;
    //either direction -> fire
    //or fire -> direction
    


}