#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int n;
    string st;
    cin >> n >> st;
    vector <vector <int>> cnts(n + 2, vector <int>(n + 2, 0));
    for (int l = 1; l <= n; l++){
        //these two loops give start & end pos
        stack <pair <string, int>> stk;
        vector <pair <int, int>> rng(n - l + 1);
        for (int i = 0; i < n - l + 1; i++){
            string subst = st.substr(i, l);
            while (!stk.empty() && stk.top().f > subst ){
                stk.pop();
            }
            if (!stk.empty()){
                rng[i].f = stk.top().s;
            } else{
                rng[i].f = -1;
            }
            stk.push({subst, i});
        }
        while (!stk.empty()) stk.pop();
        for (int i = n - l; i >= 0; i--){
            string subst = st.substr(i, l);
            while (!stk.empty() && stk.top().f >= subst){
                stk.pop();
            }
            if (!stk.empty()){
                rng[i].s = stk.top().s;
            } else{
                rng[i].s = n - l + 1;
            }
            stk.push({subst, i});
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