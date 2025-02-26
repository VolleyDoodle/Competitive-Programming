#include <bits/stdc++.h>

#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(time(nullptr));

const int inf = 1e9;
const int M = 1e9 + 7;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

void Gdfs(int v, vector<vector<int>> &sl, vector<int> &col, int c){
    col[v] = c;
    for(int u: sl[v]){
        if(col[u] == 0){
            Gdfs(u, sl, col, c);
        }
    }
}

int Fdfs(int v, vector<vector<int>> &sl, vector<int> &col, vector<int> &old_col, int c){
    col[v] = c;
    int res = 0;
    for(int u: sl[v]){
        if(col[u] == 0){
            if(old_col[u] != c) res++;
            else res += Fdfs(u, sl, col, old_col, c);
        }
    }
    return res;
}

void read_con_list(vector<vector<int>> &sl, int m){
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        sl[--u].emplace_back(--v);
        sl[v].emplace_back(u);
    }
}

void solve(int tc){
    int n, mf, mg;
    cin >> n >> mf >> mg;
    vector<vector<int>> fsl(n), gsl(n);
    read_con_list(fsl, mf);
    read_con_list(gsl, mg);

    vector<int> fcol(n), gcol(n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(gcol[i] == 0){
            Gdfs(i, gsl, gcol, i + 1);
        }
        if(fcol[i] == 0){
            ans += Fdfs(i, fsl, fcol, gcol, gcol[i]);
            if(gcol[i] < i + 1) ans++;
        }
    }
    cout << ans;
}

bool multi = true;

signed main() {
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    if (multi)cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "\n";
    }
    return 0;
}