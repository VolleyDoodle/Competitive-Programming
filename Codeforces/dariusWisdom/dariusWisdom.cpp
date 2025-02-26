#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n;
    cin >> n;
    vector <int> stones(n);
    vector <set <int>> index(3);
    vector <pair <int, int>> ans;
    for (int i = 0; i < n; i++){
        cin >> stones[i];
        index[stones[i]].insert(i);
    }
    for (int i = 0; i < n; i++){
        //look at rightmost stone with value of stones[i] - 1
        //add 1 to that and then change the set
        while (stones[i] != 0 && !index[stones[i] - 1].empty()){
            int temp = *prev(index[stones[i] - 1].end());
            if (temp < i) break;
            ans.push_back({i, temp});
            index[stones[i] - 1].erase(temp);
            index[stones[i]].erase(i);
            index[stones[i] - 1].insert(i);
            index[stones[i]].insert(temp);
            stones[i]--;
            stones[temp]++;
        }
        
    }
    cout << ans.size() << "\n";
    for (auto& event : ans){
        cout << event.f + 1 << " " << event.s + 1 << "\n";
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}