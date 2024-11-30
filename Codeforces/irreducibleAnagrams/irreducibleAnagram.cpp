#include <bits/stdc++.h>
using namespace std;
set <char> uniqueChar;
string s;
bool solve(vector <vector<int>>& prefixUnique){
    int l, r;
    cin >> l >> r;
    int count = 0;
    for (int i = 0 ; i < 26; i++){
        count+= (prefixUnique[r][i] - prefixUnique[l - 1][i]) > 0;
    }
    if (l == r || s[l - 1] != s[r - 1] || count > 2){
        return true;
    }
    return false;
}
int main(){
    
    cin >> s;

    vector <vector <int>> prefixSum(s.size() + 1, vector <int>(26, 0));
    
    for (int i = 1; i <= s.size(); i++){
        for (int x = 0; x < 26; x++){
            prefixSum[i][x] = prefixSum[i - 1][x];
        }
        prefixSum[i][s[i - 1] - 'a']++;
    }
    int t;
    cin >> t;
    while (t--){
        bool yn = solve(prefixSum);
        cout << (yn ? "YES" : "NO") << "\n";
    }

}