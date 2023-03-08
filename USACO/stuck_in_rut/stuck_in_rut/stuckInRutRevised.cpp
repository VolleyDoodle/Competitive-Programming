#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector <pair <int, int>> northCows, eastCows;
    vector <vector <int>> events;
    vector <int> distN(n, pow(10, 9) + 1), distE(n, pow(10, 9) + 1);
    vector <bool> NorE(n);
    for (int i = 0; i < n; i++){
        int tX, tY; char tType;
        cin >> tType >> tX >> tY;
        if (tType == 'N'){ NorE[i] = true;}
        (tType == 'N' ? northCows.push_back({tX, tY}) : eastCows.push_back({tX, tY}));
    }
    //cout << "h";
    //below finds all possible events
    pair <int, int > nCow, eCow;
    for (int i = 0; i < northCows.size(); i++){
        for (int x = 0; x < eastCows.size(); x++){
            nCow = northCows[i]; eCow = eastCows[x];
            if (eCow.second > nCow.second && nCow.first > eCow.first && nCow.first - eCow.first != eCow.second - nCow.second){
                //checking if plausible that two cows can interact and if they have not stopped
                int stopTime = max(nCow.first - eCow.first, eCow.second - nCow.second);
                events.push_back ({stopTime, i, x});
            }
        }
    }
    sort(events.begin(), events.end());
    //cout << 'h';
    for (auto event : events){
        nCow = northCows[event[1]]; eCow = eastCows[event[2]];
        if (nCow.second + distN[event[1]] >= eCow.second && eCow.first + distE[event[2]] >= nCow.first){
            if (nCow.first - eCow.first > eCow.second - nCow.second){
                //east cow stopps
                distE[event[2]] = nCow.first - eCow.first;
            } else{
                distN[event[1]] = eCow.second - nCow.second;
            }
        }
    }
    //cout << 'h';
    //below code checks if stopped events actually happen
    int nC = 0, eC = 0;
    vector <int> ans;
    for (int i = 0; i < n; i++){
        if (NorE[i]){
            ans.push_back(distN[nC]);
            nC++;
        } else{
            ans.push_back(distE[eC]);
            eC++;
        }
        if (ans[i] == pow(10, 9) + 1){
            cout << "Infinity\n";
            continue;
        }
        cout << ans[i] << "\n";
    }
    


}