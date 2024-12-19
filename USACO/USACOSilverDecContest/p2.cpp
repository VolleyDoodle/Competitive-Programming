#include <bits/stdc++.h>
using namespace std;
bool possible(pair<int, int>& tree, vector <vector<int>>& laws, map<int, int>& pSum);
void changeTree(pair<int, int>& tree, vector <vector<int>>& laws, map<int, int>& pSum);
//can solve in NK time
void solve(){
    int n, k;
    cin >> n >> k;
    vector <pair <int, int>> trees;
    vector <vector <int>> laws;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        trees.push_back({temp, 0});
    }
    sort(trees.begin(), trees.end());
    for (int i = 0; i < k; i++){
        //trees can never be created!!
        int l, r, t;
        cin >> l >> r >> t;
         auto newl = lower_bound(trees.begin(), trees.end(), l, [](const pair<int, int>& p, int val) {
            return p.first < val;
        });
        auto newr = upper_bound(trees.begin(), trees.end(), r, [](int val, const pair<int, int>& p) {
            return val < p.first; 
        });
        --newr;
        if (newl == trees.end() || newr == trees.begin()) continue;
        laws.push_back({(*newl).first, (*newr).first, t});
    }
    map <int, int> pSum;
    for (auto element: trees){
        pSum[element.first] = 0;
    }
    sort(laws.begin(), laws.end());
    for (auto curLaw : laws){
        pSum[curLaw[0]]++;
        auto it = pSum.find(curLaw[1]);
        ++it;
        if (it != pSum.end()){
            it->second--;
        }
    }
    int curSum = 0;
    map <int, int> pSumTree;
    int prev = 0;
    for (auto& tree : trees){
        pSumTree[tree.first] = prev + 1;
        prev = pSumTree[tree.first];
    }
    //sets up usefull index
    for (int i = 0; i < n; i++){
        curSum+=pSum[trees[i].first];
        //pSum[trees[i].first] = curSum;
        trees[i].second+=curSum;
    }
    sort(trees.begin(), trees.end(), []
    (auto& a, auto& b){
        return a.second < b.second;
    });
    int ans = 0;
    for (auto& tree : trees){
        if (tree.second == 0){
            ans++;
            continue;
        }
        if (possible(tree, laws, pSumTree)){
            ans++;
            changeTree(tree, laws, pSumTree);
        }
    }
    cout << ans;
}
void changeTree(pair<int, int>& tree, vector <vector<int>>& laws, map<int, int>& pSum){
    auto it = upper_bound(laws.begin(), laws.end(), tree.first, [](int val, const vector<int>& law) {
        return val < law[0];  // Compare int with the first element of the law
    });
    if (it == laws.begin()){
        return;
    }
    --it;
    while ((*it)[0] == tree.first){
        (*it)[2]++;
        --it;
        if (it == laws.begin() - 1){
            break;
        }
    }
}   
bool possible(pair<int, int>& tree, vector <vector<int>>& laws, map<int, int>& pSum){
    auto it = upper_bound(laws.begin(), laws.end(), tree.first, [](int val, const vector<int>& law) {
        return val < law[0];  // Compare int with the first element of the law
    });
    if (it == laws.begin()){
        return true;
    }
    --it;
    while ((*it)[0] <= tree.first){
        auto it2 = pSum.find((*it)[0]);
        it2--;
        if (pSum[(*it)[1]] - it2->second - 1 < (*it)[2]){
            return false;
        }
        --it;
        if (it == laws.begin() - 1){
            break;
        }
    }
    return true;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}