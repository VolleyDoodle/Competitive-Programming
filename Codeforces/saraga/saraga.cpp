#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    string s;
    string t;
    cin >> s >> t;
    if (s.size() == 1 || t.size() == 1){
        cout << -1;
        return 0;
    }
    map <char, vector <int>> sLocs, tLocs;

    for (int i = 1; i < s.size(); i++){
        sLocs[s[i]].push_back(i);
    }
    for (int i = t.size() - 2; i >= 0; i--){
        tLocs[t[i]].push_back(i);
    }
    int curAnsLen = INT_MAX;
    char curAnsCh = 'Z';
    for (auto& element : sLocs){
        if (tLocs.count(element.first) == 0){
            continue;
        }
         else if (curAnsLen > element.second[0] + (t.size() - tLocs[element.first][0])){
            curAnsLen = element.second[0] + (t.size() - tLocs[element.first][0]);
            curAnsCh = element.first;
        }
    }
    if (curAnsLen == INT_MAX){
        cout << -1;
        return 0;
    }
    string ans = s.substr(0, sLocs[curAnsCh][0]) + t.substr(tLocs[curAnsCh][0]);
    cout << ans;

}