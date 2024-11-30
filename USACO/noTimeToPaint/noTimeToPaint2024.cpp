#include <bits/stdc++.h>
using namespace std;
int n, q;
vector <vector <int>> pSum;
void solve(string s, vector <vector<int>>& numberChar, vector <int>& lastLoc, vector <int>& ans){
    for (int i = 1; i <= n; i++){
        //light[i][x] stores all the lighter characters of character 'x' at i
        ans[i] = ans[i - 1];
        numberChar[i][s[i] - 'A']++;
        for (int j = 0; j < 26; j++){
            numberChar[i][j] += numberChar[i - 1][j];
        }
        int numColorsLighterLast = 0, numColorsLighterCur = 0;
        for (int j = s[i] - 'A' - 1; j >= 0; j--){
            numColorsLighterLast+=numberChar[lastLoc[s[i] - 'A']][j];
            numColorsLighterCur+=numberChar[i][j];
            
        }
        if (numColorsLighterCur != numColorsLighterLast || lastLoc[s[i] - 'A'] == 0){
            ans[i]++;
        }
        lastLoc[s[i] - 'A'] = i;
        

    }
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    cin >> n >> q;
    //basiclaly  just build strig from left to right then right to left
    //then just print answers
    //dont actually care about each letter, just how "light they are"
    string s;
    cin >> s;
    s = '#' + s;
    vector <vector <int>> numberChar(n + 1, vector <int>(26, 0));
    vector <int> lastLoc(26, 0);
    vector <int> ans(n + 1, 0);
    solve(s, numberChar, lastLoc, ans);

    reverse(s.begin() + 1, s.end());
    vector <vector <int>> numberCharR(n + 1, vector <int>(26, 0));
    vector <int> lastLocR(26, 0);
    vector <int> ansR(n + 1, 0);
    solve(s, numberCharR, lastLocR, ansR);


    reverse(ansR.begin() + 1, ansR.end());
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        if (a == 1 && b == n){
            cout << 0;
        }
        else if (a == 1){
            cout << ansR[b + 1];
        } else if (b == n){
            cout << ans[a - 1];
        } else{
            cout << ans[a - 1] + ansR[b + 1];
        }
        cout << "\n";
    }
    
}