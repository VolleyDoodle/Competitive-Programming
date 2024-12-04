#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, maxLoc, minLoc;
    cin >> n;
    //what
    string s;
    cin >> s;
    if (n == 1){
        cout << s << "\n";
        return;
    }
    vector <int> counts(26, 0);
    vector <bool> visited(26, false);
    for (int i = 0; i < n; i++){
        counts[s[i] - 'a']++;
    }
    maxLoc = s[0] - 'a'; minLoc = s[0] - 'a';
    visited[s[0] - 'a'] = true;
    for (int i = 1; i < n; i++){
        if (visited[s[i] - 'a']) continue;
        if (counts[s[i] - 'a'] >= counts[maxLoc]){
            maxLoc = s[i] - 'a';
        } else if (counts[s[i] - 'a'] <= counts[minLoc]){
            minLoc = s[i] - 'a';
        }
        visited[s[i] - 'a'] = true;
    }
    for (int i = 0; i < n; i++){
        if (s[i] - 'a' == minLoc){
            s[i] = (char) (maxLoc + 'a');
            break;
        }
    }
    
    cout << s << "\n";
    

}
int main(){

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}