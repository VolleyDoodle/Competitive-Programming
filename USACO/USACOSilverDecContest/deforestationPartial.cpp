#include <bits/stdc++.h>
using namespace std;
#define f first 
#define s second 
//can solve in O(n log n)
//basically sweep line approach
//split each interval intro entry and end
//keep track of how many trees and what current itnervals are on
//if the list of intervals are empty, then any tree we encounter
//can be removed
//5 out of 11 test cases
void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> trees;
    vector <vector <int>> events;
    //{pos, type, id}
    //this is O(n * k) solution
    //practice line sweep anway + in-contest
    for (int i = 0; i < n; i++){
        int t1;
        cin >> t1;
        trees.push_back(t1);
        events.push_back({t1, 1, -1});
    }
    //pos, type, index, trees possible to cut
    //sort(events.begin(), events.end());
    sort(trees.begin(), trees.end());
    //posToCut stores number of trees that can be removed for each law
    vector <int> posToCut(k);
    for (int i = 0; i < k; i++){
        int l, r, t;
        cin >> l >> r >> t;
        events.push_back({l, 0, i});
        events.push_back({r, 2, i});
        auto it1 = lower_bound(trees.begin(), trees.end(), l);
        auto it2 = upper_bound(trees.begin(), trees.end(), r);
        posToCut[i] = (it2 - it1) - t;
    }
    sort(events.begin(), events.end());
    //curLaws stores the indexes of laws currently
    
    set <int> curLaws;
    vector <int> curTrees(k, 0);
    int ans = 0;
    for (int i = 0; i < events.size(); i++){
        vector <int> event = events[i];
        if (event[1] == 1){
            //tree
            //basically now checking if possible to remove this tree
            bool remove = true;
            for (auto& law : curLaws){
                if (posToCut[law] <= 0) remove = false;
            }
            if (remove){
                for (auto& law : curLaws) posToCut[law]--;
                ans++;
            }
        } else if (event[1] == 0){
            //end of an interval as we are doing right to left
            curLaws.insert(event[2]);
        } else if (event[1] == 2){
            curLaws.erase(event[2]);
        }
    }
    cout << ans;

}

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}