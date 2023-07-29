#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    map<pair<string, string>, int> info;
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        string t, tt; cin >> t >> tt;
        string temp = string() + t[0] + t[1];
        info[{temp, tt}]++;
    }
    int ans = 0;
    for (auto element: info){
        if(element.first.first != element.first.second){
            ans+= info[element.first] * info[{element.first.second, element.first.first}];
        }
        
        //cout << element.first.first << element.first.second << endl;
    }
    cout << ans/2;
   // cout << "h";
}