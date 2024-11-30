#include <bits/stdc++.h>
using namespace std;
void solve(){
    string t1, t2;
    cin >> t1 >> t2;
    map <char, char> m;
    map<char, bool> visited;
    for (int i = 0; i < t1.size(); i++){
        m[t1[i]] = t2[i];
        visited[t1[i]] = false;
    }
    int ans = 0;
    for (auto& element : m){
        int tAns = 0;
        if (!visited[element.first]){
            //visit all in the cycle...
            char curElement = element.first;
            while(m.count(curElement)){
                tAns++;
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}