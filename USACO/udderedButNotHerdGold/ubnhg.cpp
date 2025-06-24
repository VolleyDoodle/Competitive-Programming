#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    string s;
    cin >> s;
    int n = s.size();
    //make_new[i][j], basically means letter i comes after letter j, so evertyime we see ij, its going to be new alphabet

    set <char> unique;
    for (int i = 0; i < n; i++) unique.insert(s[i]);

    int bit_len = unique.size();
    vector <char> arr;
    for (char ch : unique) arr.push_back(ch);

    vector <vector <int>> make_new(bit_len, vector <int>(bit_len, 0));
    for (int i = 0; i < bit_len; i++){
        for (int j = 0; j < bit_len; j++){
            //basically trying to update
            //letter i comes after letter j
            //so need need to check for i j
            for (int x = 0; x < n - 1; x++){
                if (s[x] == arr[i] && s[x + 1] == arr[j]){
                    make_new[i][j]++;
                }
            }
        }
    }
    vector <int> dp(1 << bit_len, 1e6);
    dp[0] = 0;
    for (int set = 0; set < (1 << bit_len); set++){
        for (int j = 0; j < bit_len; j++){
            if (set & (1 << j)){
                //use set / {j}
                int num = 0;
                for (int i = 0; i < bit_len; i++){
                    if (set & (1 << i)) num += make_new[j][i];
                }
                dp[set] = min(dp[set], dp[set ^ (1 << j)] + num);
            }
        }
    }
    cout << dp[(1 << bit_len) - 1] + 1;
}