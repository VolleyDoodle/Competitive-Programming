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
    setIO("snowboots");
    int n, b;
    cin >> n >> b;
    vector <vector <int>> f(n, vector <int>(2));
    for (int i = 0; i < n; i++){
        cin >> f[i][0];
        f[i][1] = i + 1;
    }
    sort(f.begin(), f.end());
    vector <vector <int>> boots(b, vector <int>(3));
    for (int i = 0; i < b; i++){
        cin >> boots[i][0] >> boots[i][1];
        boots[i][2] = i;
    }
    sort(boots.begin(), boots.end());


    set <int> gaps;
    for (int i = 0; i <= n + 1; i++){
        gaps.insert(i);
    }
    //multiset <int> bestAns;
    int tileIdx = n - 1;
    vector <bool> ans(b, 0);
    int maxDist = 0;
    for (int i = b - 1; i >= 0; i--){
        while (tileIdx >= 0 && f[tileIdx][0] > boots[i][0]){
            maxDist = max(maxDist, *(gaps.upper_bound(f[tileIdx][1])) - *(prev(gaps.lower_bound(f[tileIdx][1]))) - 1);
            gaps.erase(gaps.find(f[tileIdx][1]));
            tileIdx--;
             
        }
        ans[boots[i][2]] = (boots[i][1] > maxDist);
    }
    for (int i = 0; i < b; i++){
        cout << ans[i] << "\n";
    }


}