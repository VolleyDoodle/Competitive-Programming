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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        bool yes = false;
        vector <int> a(2 * n);
        string s;
        for (int i = 0; i < 2 * n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 2 * n - 2; i >= 0; i--){
            //must always start with largest element
            //vector <bool> visited(2 * n, 0);
            bool bad = false;
            vector <pair <int, int>> ans;
            map <int, int> cnt;
            for (int x = 0; x < 2 * n; x++) cnt[a[x]]++;
            cnt[a[2 * n - 1]]--;
            cnt[a[i]]--;
            int curSum = a[2 * n - 1];

            ans.push_back({a[2 * n - 1], a[i]});
            for (int j = 2 * n - 1; j >= 0; j--){
                if (cnt[a[j]] == 0){
                    continue;
                }
                int otherVal = curSum - a[j];
                cnt[a[j]]--;
                if (cnt[otherVal] == 0){
                    bad = true;
                    break;
                }
                curSum = a[j];
                cnt[otherVal]--;
                ans.push_back({a[j], otherVal});
            }
            if (!bad){
                yes = 1;
                cout << "YES\n";
                cout << ans[0].first + ans[0].second << "\n";
                for (const auto& p : ans){
                    cout << p.first << " " << p.second << "\n";
                }
                break;
            }
        }
        if (!yes) cout << "NO\n";
        
    }
}