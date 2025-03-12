#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
//gotta use lcp :
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    //AGTCAACG
    int n;
    string st;
    cin >> n >> st;
    vector <vector <int>> cnts(n + 2, vector <int>(n + 2, 0));
    vector <vector <int>> lcp(n + 2, vector <int>(n + 2, 0));
    vector <string> suff(n);
    string cur = "";
    for (int i = n - 1; i >= 0; i--){
        cur += st[i];
        string temp = cur;
        reverse(temp.begin(), temp.end());
        suff[i] = temp;
    }
    for (int i = n - 1; i >= 0; i--){
        for (int j = i - 1; j >= 0; j--){
            if (st[i] == st[j]){
                lcp[i][j] = 1 + lcp[i + 1][j + 1];
            } else{
                lcp[i][j] = 0;
            }
            lcp[j][i] = lcp[i][j];
        }
    }
    for (int l = 1; l <= n; l++){
        //these two loops give start & end pos
        stack <pair <string, int>> stk;
        vector <pair <int, int>> rng(n - l + 1);
        for (int i = 0; i < n - l + 1; i++){
            while (!stk.empty()){
                int val = lcp[stk.top().s][i];
                if (val >= l) break;
                if (val < l && st[stk.top().s + val] < st[i + val]){
                    break;
                }
                stk.pop();
            }
            if (!stk.empty()){
                rng[i].f = stk.top().s;
            } else{
                rng[i].f = -1;
            }
            stk.push({"", i});
        }
        while (!stk.empty()) stk.pop();
        //to the right (endpt)
        for (int i = n - l; i >= 0; i--){  
            while (!stk.empty()){
                int val = lcp[stk.top().s][i];

                if (val < l && st[stk.top().s + val] < st[i + val]){
                    break;
                }
                stk.pop();
            }
            if (!stk.empty()){
                rng[i].s = stk.top().s;
            } else{
                rng[i].s = n - l + 1;
            }
            stk.push({"", i});
        }
        //now do da calculations
        for (int i = 0; i < n - l + 1; i++){
            int maxN = ((rng[i].s + l - 2) - (rng[i].f));
            cnts[l][l]++;
            cnts[l][maxN + 1]--;
        }
    }
    vector <int> ans(n + 1, 0);
    for (int l = 1; l <= n; l++){
        int cur = 0;
        for (int k = l; k <= n; k++){
            cur+=cnts[l][k];
            ans[cur]++;
        }
    }
    for (int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
}