#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
void monStack(vector <int>& h){
    stack <int> vals;
    for (int i = h.size() - 1; i >= 0; i--){
        while (!vals.empty() && h[vals.top()] < h[i]){
            vals.pop();
        }
        if (!vals.empty()){
            ans += vals.top() - i + 1;
        }
        vals.push(i);
    }

}
void orderSet(vector <int>& h){
    vector <int> idx(h.size() + 1);
    for (int i = 0; i < h.size(); i++){
        idx[h[i]] = i;
    }
    set <int> vals;
    for (int i = h.size(); i >= 1; i--){
        auto it = vals.insert(idx[i]).first;
        if (next(it) != vals.end()) ans += *(next(it)) - *it + 1;
        
    }
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int n;
    cin >> n;
    
    vector <int> h(n), idx(n + 1);
    
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }
    /*monStack(h);
    reverse(h.begin(), h.end());
    monStack(h);
    dw, monStack fn works
    */
    //orderest set function is essentially the monotonic stack
    //but ig easier idk?
    orderSet(h);
    reverse(h.begin(), h.end());
    orderSet(h);
    cout << ans;
}