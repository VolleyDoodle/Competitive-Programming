#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> a(n), b(n);
    vector <pair <int, int>> events;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++){
        events.push_back({a[i], 0});
        events.push_back({b[i], 1});
    }
    sort(events.begin(), events.end());
    
    int index = 0, ppl = n, negR = 0;
    long long ans = 0;
    while (index < 2 * n){
        int curNum = events[index].f;
        int addedNeg = 0, losePpl = 0;
        while (curNum == events[index].f){
            //while loop is to make usre all events that have equal nums
            //are all proccessed at the same time
            if (events[index].s == 0){
                // a event
                addedNeg++;

            } else if (events[index].s == 1){
                // b event
                losePpl++;
                addedNeg--;
            }
            index++;
        }
        
        if (negR <= k){
            ans = max(ans, (long long)(ppl) * curNum);
        }
        negR+=addedNeg;
        ppl-=losePpl;
        /*if (negR <= k){
            ans = max(ans, (long long)(ppl) * curNum);
        }*/
        
    }
    cout << ans;

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