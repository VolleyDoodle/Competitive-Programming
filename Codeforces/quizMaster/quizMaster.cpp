#include <bits/stdc++.h>
using namespace std;
set <int> needTopics, curTopics;
void findFactorsAndDo(int& element, int addOrSubtract, vector <int>& keepTrack){
    for (int i = sqrt(element); i >= 1; i--){
        if (element%i == 0 && i < keepTrack.size()){
            keepTrack[i]+=addOrSubtract;
            
            if (keepTrack[i] == 1 && addOrSubtract == 1){
                curTopics.insert(i);
            } 
            else if (keepTrack[i] == 0) {
                curTopics.erase(i);
            }
            if (element/i < keepTrack.size() && element/i != i){
                keepTrack[element/i]+=addOrSubtract;
                if (keepTrack[element/i] == 1 && addOrSubtract == 1){
                    curTopics.insert(element/i);
                } 
                else if (keepTrack[element/i] == 0) {
                    curTopics.erase(element/i);
                }
            }
            
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        needTopics.insert(i);
    }
    vector <int> a(n), keepTrack(m + 1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    //ddddd
    sort(a.begin(), a.end());
    int left = 0, right = 0, ans = INT_MAX;
    bool changed = false;
    findFactorsAndDo(a[0], 1, keepTrack);
    while (right < n && left <= right){
        if (curTopics.size() != needTopics.size()){
            right++;
            if (right == n) break;
            findFactorsAndDo(a[right], 1, keepTrack);
        } else{
            changed = true;
            ans = min(ans, a[right] - a[left]);
            findFactorsAndDo(a[left], -1, keepTrack);
            left++;
            
        }
    }
    cout << (changed ? ans : -1)  << "\n";
    needTopics.clear();
    curTopics.clear();
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}