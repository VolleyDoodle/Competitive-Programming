#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector <vector <int>> cnt(2, vector<int>(26, 0));
    //first vector is odd, second vector is even
    for (int i = 0; i < n; i++){
        cnt[i%2][s[i] - 'a']++;
    }
    if (s.size()%2 == 0){
        vector <int> maxes(2, 0);
        for (int i = 0; i < 2; i++){
            for (int x = 0; x < 26; x++){
                maxes[i] = max(maxes[i], cnt[i][x]);
            }
        }
        cout << n - (maxes[0] + maxes[1]);
        return;
    } else{
        //odd is a tad bit more tricky
        vector <vector <int>> curCnt(2, vector<int>(26, 0));
        //essentially, just finding the shift where the most elements line up together
        //so not that tricky tbh
        int ans = 0;
        for (int i = 0; i < n; i++){
            //pretend removing at pos i
            vector <int> maxes(2, 0);
            for (int j = 1; j >= 0; j--){
                for (int x = 0; x < 26; x++){
                    maxes[j] = max(maxes[j], curCnt[j][x] + (cnt[(j + 1)%2][x] - curCnt[(j + 1)%2][x]) - (s[i] - 'a' == x && (i + 1)%2 == j));
                    //this last part basically just makes sure that we are not counting the letter that we are deleting
                    //first checks if the value is the same, and then just checks if it is in cnt[]
                }
            }
            ans = max(ans, maxes[0] + maxes[1]);
            curCnt[i%2][s[i] - 'a']++;
        }
        cout << n - ans;

    }
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}