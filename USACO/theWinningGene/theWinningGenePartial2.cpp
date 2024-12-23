#include <bits/stdc++.h>
using namespace std;
vector <long long> ans;
string s;
int n;
//literally just brute force
//did it cause good way to debug final sol
// 7/15 test cases (hopefully?)
void solve(int& k, int& l){
    vector <string> lstrings;
    //cout << k << " " << l << "\n";
    string curL = s.substr(0, l);
    lstrings.push_back(curL);
    for (int i = 0; i < n - l; i++){
        curL.erase(0, 1);
        curL.push_back(s[i + l]);
        lstrings.push_back(curL);
    }
    set <pair <string , int>> curLs;
    set <int> pos;
    for (int i = 0; i < (k - l) + 1; i++){
        curLs.insert({lstrings[i], i});
    }
    for (int i = 0; i < lstrings.size() - (k - l) - 1; i++){
        //basically removing lstring[i]
        //and adding lstring[i + k] to set
        pos.insert(curLs.begin()->second);
        curLs.erase({lstrings[i], i});
        curLs.insert({lstrings[i + (k - l) + 1], i + (k - l) + 1});
    }
    pos.insert(curLs.begin()->second);
    ans[pos.size()]++;
        

}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);


    cin >> n >> s;
    ans.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= i; x++){
            solve(i, x);
        }
    }
    for (int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
}