#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector <char> s;
    for (int i = 0; i < n; i++){
        char t;
        cin >> t;
        s.push_back(t);
    }
    if (s.size() <= 1){
        cout << "YES";
        return;
    }
    int left = 0, right = s.size() - 1;
    
    if (s[0] == 's') left++;
    if (s[s.size() - 1] == 'p') right--;
    
    if (left > right){
        cout << "YES";
        return;
    }
    char c = '.';
    for (int i = left; i <= right; i++){
        if (c == '.' && s[i] != '.') c = s[i];
        if (s[i] != c && s[i] != '.'){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}