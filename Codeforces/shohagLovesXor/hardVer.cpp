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
    //lokwey one of the top 5 most lleresting problems
    ll x, m;
    cin >> x >> m;
    set <ll> ans;
    //basically if x > y
    //then x ^ y only need to check for y
    ll cnt = 0;
    for (ll y = 1; y <= min(x, m); y++){
        ll p = x ^ y; 
        if (p%y == 0){
            cnt++;
           // ans.insert(y);
        }
    }
    //technically cuz im a dumbass, i would just binary search on the biggest x ^ y (such that it is multiple of x) and y <= m
    //binary search doesnt even work
    //ll p = m + x;
    ll p = m - m%x;
    cnt+= (m - x)/x;
    //x ^ p = y btw
    if ((x ^ p) > min(x, m) && (x ^ p) <= m){
        cnt++;
    }
    p+=x;
    if ((x ^ p) > min(x, m) && (x ^ p) <= m) cnt++;
    if (x <= m && (m - x) >= x) cnt--;
    cout << cnt;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    ll t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}