#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("input.in", "r", stdin);
    //eopen("output.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector <int> boys(n);
    for (int i = 0; i < n; i++){
        cin >> boys[i];
    }
    cin >> m;
    vector <int> girls(m);
    for (int i = 0; i < m; i++){
        cin >> girls[i];
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int boyIndex = 0, ans = 0;
    for (int x = 0; x < n; x++){
        for (int i = 0; i < m; i++){
            if (abs(boys[x] - girls[i]) <= 1){
                ans++;
                boys[x] = -1; girls[i] = -3;
            }
        }
    }
    
    cout << ans;


}