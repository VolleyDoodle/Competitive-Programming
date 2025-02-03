#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    string ans = "";
    ll n;
    cin >> n;
    vector <ll> a(n);
    set <ll> zeroIndex;
    set <ll, greater <ll>> oneIndex;
    for (ll i = 0; i < n; i++){
        cin >> a[i]; a[i]--;
        if (a[i] == 1) oneIndex.insert(i);
    }
    a.push_back(0);
    zeroIndex.insert(n);
    oneIndex.insert(-1);
    ans += string(n, 'R');
    //lets set some rules
    //at the end index all elements before (not inclusive) and for start all elements after (not inclusive)
    while (*zeroIndex.begin() != 0){
        //this can go from zero index begin to first index begin
        ll end = *(zeroIndex.begin()), start = *(oneIndex.begin());
        if (end == 0) break;
        if (end - 1 == start){
            ans += "L";
            a[start]--;
            zeroIndex.insert(start);
            oneIndex.erase(oneIndex.begin());
            //cout << ans;
            continue;
        }
        for (ll i = end - 1; i > start; i--){
            a[i]--;
            //if (a[i] == 1) oneIndex.insert(i);
            if (i < n && i >= 0) ans += "L";
        }
        for (ll i = start + 1; i < end; i++){
            a[i]--;
            if (a[i] == 1) oneIndex.insert(i);
            if (i < n) ans += "R";
        }
    }
    cout << ans;
}