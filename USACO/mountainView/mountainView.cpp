#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out","w", stdout);
    int n; cin >> n; //cout << n;
    vector <pair <int, int>> peaks(n), base(n); 
   
    for (int i = 0; i < n; i++){
        cin >> peaks[i].first >> peaks[i].second;
        base[i].first = peaks[i].first - peaks[i].second;
        base[i].second = peaks[i].first + peaks[i].second;
    }
    sort(base.begin(), base.end(), [](const pair <int, int> a, const pair <int, int> b){return a.first < b.first;});
    int ans = n, maxHeight = INT_MIN;
    for (int i = 0; i < n; i++){
        if (base[i].second > maxHeight){
            maxHeight = base[i].second;
            continue;
        }
        ans--;
        
    }
    cout << ans;
}