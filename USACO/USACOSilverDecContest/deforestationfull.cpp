#include <bits/stdc++.h>
using namespace std;
#define f first 
#define s second 
//can solve in O(n log n)
//basically sweep line approach
//split each interval intro entry and end
//keep track of how many trees and what current itnervals are on
//will completely solve later ;9
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
    //count stores #chopped trees
    //alright so multiset basically stores the minimum# of trees we can cut in all the intervals
    //issue arises, once an interval ends how do we erase?
    //and how do we keep track?
    //so when we "remove" a tree which would be -1 to each of the possible trees we can cut
    //we instead just add +1 to everything in the future (add 1 to cnt)
    //basically the whole idea of this problem (essentially)
    set <int> curLaws;
    multiset <int> curPosToCut; //first  = # of trees pos to cut, second = "event" index
    //curPosToCut.insert(-1e9 - 7);
    vector <int> curTrees(k, 0);
    int cnt = 0;
    map <int, int> idToCnt; //maps the id of the interval to the cnt at the start pos of interval
    for (int i = 0; i < events.size(); i++){
        vector <int> event = events[i];
        if (event[1] == 1){
            //tree
            //basically now checking if possible to remove this tree
            auto it = curPosToCut.begin();
            if (curPosToCut.empty() || *it - cnt > 0){
                //possible to cut ;)
                cnt++;
            }
        } else if (event[1] == 0){
            //start of interval
            curPosToCut.insert(posToCut[event[2]] + cnt);
            idToCnt[event[2]] = cnt;
        } else if (event[1] == 2){
            curPosToCut.erase(curPosToCut.find(idToCnt[event[2]] + posToCut[event[2]]));
        }
    }
    cout << cnt;

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