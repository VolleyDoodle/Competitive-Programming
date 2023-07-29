#include <bits/stdc++.h>
using namespace std;
const int bigNum = 1e5 + 3;
bool visited[bigNum];
int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    
    cin >> n;
    vector <int> elsie(n), bessie;
    for (int i = 0; i < n; i++){
        cin >> elsie[i];
        visited[elsie[i]] = true;
    }
    for (int i = 1; i <= 2 * n; i++){
        if (!visited[i]){
            bessie.push_back(i);
        }
    }
    sort(elsie.begin(), elsie.end());
    sort(bessie.begin(), bessie.end());
    for (int i = 0; i < n; i++){
        auto it = lower_bound(bessie.begin(), bessie.end(), elsie[i]);
        if (it == bessie.end()){ continue;}
        ans++;
        bessie.erase(bessie.begin() + (it - bessie.begin()));
        
    }
    cout << ans;
}