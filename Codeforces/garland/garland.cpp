#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector <vector <int>> indexs(26), diffArray(26); //stores index of string (from a..z)
//diffArray stores gap distance
vector <int> minIndex(26); //stores what index in indexs where we should start two-pointers from
void solve(){
    int m; char c;
    cin >> m >> c;

    vector <int> curIndexL = indexs[c - 'a'];
    if (curIndexL.size() == 0){
        cout << m << "\n";
        return;
    }
    int curAns = 0;
    int left = 0, right = 0;
    while (left <= right && right < curIndexL.size()){
        while ((curIndexL[right] - curIndexL[left]) - (right - left) > m){
            left++;
        }
        int tempAns = (right - left) + 1 + m;
        curAns = max(curAns, tempAns);
        right++;

    }
    cout << min(n, curAns) << "\n";
    
}
int main(){
    int q;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++){
        indexs[s[i] - 'a'].push_back(i);
    }
    /*for (int i = 0; i < 26; i++){
        int minDiff = INT_MAX;
        for (int x = 0; x < indexs[i].size() - 1; x++){
            diffArray[i].push_back(indexs[i][x + 1] - indexs[i][x]);
        }

    }*/

    cin >> q;
    while (q--){
        solve();
    }
}