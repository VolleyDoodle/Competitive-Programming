#include <bits/stdc++.h>
using namespace std;
//alright
//essentially, the problem is not too complicated
//first notice that in the folder list, once you go down, the first folder (upmost) can never be visited again
//this suggests greedy strategy(?) where you take all emails that need that folder and see if you can "remove" all of them
//we can use dequeue for this? (need stack stuff for last part where we add to beginning)
//probably use two (de)queues for this, just keep on popping and 
void solve(){
    int m, n, k;
    cin >> m >> n >> k;
    //ahh seems a struggle to implement ;(
    vector <int> emailToFolders(n);
    for (int i = 0; i < n; i++) cin >> emailToFolders[i];
    deque<int> email;
    email.push_back(0);
    int low = 1, high = k, index = 0;
    while (!email.empty){
        while (email.size() != k){
            email.push_back(emailToFolders[index++]);
        }

    }
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

}