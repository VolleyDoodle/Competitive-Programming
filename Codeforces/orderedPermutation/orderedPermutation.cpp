#include <bits/stdc++.h>
using namespace std;
void recurse(int l, int r, long long k, vector <int>& ans, int curNum){
    int curSize = r - l;
    //ok, curSize represents current size, literally
    //(n - 1) - 0 + 1 => n, at start
    //no
    if (curSize == -1){
        return;
    }
    if (curSize <= 63 && k > (1LL << (curSize - 1))){
        //lexographically bigger half
        //
        k -= (1LL << (curSize - 1));
        ans[r] = curNum;
        recurse(l, r - 1, k, ans, curNum + 1);


    } else{
        //if curSize reallly really big
        //then basically going to be lexographically smaller part
        //
        ans[l] = curNum;
        recurse(l + 1, r, k, ans, curNum + 1);
    }
}
void solve(){
    int n;
    long long k;
    cin >> n >> k;
    //very cool problem
    /*
    2^(n - 1) total ways for S(p) to be maximized cuz edges have lowest weights
    */
    //2^40 is greater than 10^12, so if n >= 41, then always possible to find sol
    if (n < 41 && k > (1LL << (n - 1))){
        cout << -1;
        return;
    }
    vector <int> ans(n);
    recurse(0, n - 1, k, ans, 1);
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

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