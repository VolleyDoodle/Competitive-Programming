#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector <pair <int, int>> upMore, downMore; //saves indices
    vector <pair <int, int>> grid(n);
    for (int i = 0; i < n; i++){
        cin >> grid[i].first;
    }

    int upSum = 0, downSum = 0;
    for (int i = 0; i < n; i++){
        cin >> grid[i].second;
        if (grid[i].second > grid[i].first){
            downSum+=grid[i].second;
            downMore.push_back({grid[i].second, i});
        } else{
            upSum+=grid[i].first;
            upMore.push_back({grid[i].first, i});
        }
    }
    /*sort(upMore.begin(), upMore.end(),[&grid]
        (const auto& a, const auto& b){
            return a.first + grid[a.second].second < b.first + grid[b.second].second;
        }
    );
    sort(downMore.begin(), downMore.end(),[&grid]
        (const auto& a, const auto& b){
            return a.first + grid[a.second].first > b.first + grid[b.second].first;
        }
    );*/
    int ans = INT_MIN;
    for (int i = 0; i < upMore.size(); i++){
 
        ans = max(ans, upSum + downSum + grid[upMore[i].second].second);
    }
    for (int i = 0; i < downMore.size(); i++){
        ans = max(ans, upSum + downSum + grid[downMore[i].second].first);
    }
    cout << ans;
    


    
}
int main(){
    int t;
    cin >> t;
    while (t--){
        //cout << "ans: ";
        solve();
        cout << "\n";
    }
}