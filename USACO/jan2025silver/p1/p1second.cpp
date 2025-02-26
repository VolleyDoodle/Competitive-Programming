#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int bigNum = 5 * 1e5 + 1; //5 * 1e5 + 1;
ll check(vector <ll>& a, vector <ll>& b){
    ll sum = 0;
    for (ll i = 0; i < a.size(); i++){
        sum += (a[i] == b[i]);
    }
    return sum;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    ll n, ans = 0;
    cin >> n;
    vector <ll> a(n), b(n), ca(n);
    vector <vector <int>> graph(bigNum);
    for (ll i = 0; i < n; i++){
        cin >> a[i];
        ca[i] = a[i];
    }
    //n(n - 1)/2 somehtiing is not affectd
    //int amt = n * (n - 1)/2;
    for (int i = 0; i < n; i++){
        cin >> b[i];
        graph[b[i]].push_back(i);
    }
    for (int i = 0; i < n; i++){
        for (int idx : graph[a[i]]){
            if (i <= idx){
                //other one is bigger
                ans += min((ll)n - idx, (ll)i + 1);
                //cout << "i: " << i << "idx: " << idx << "\n";
            } else if (i > idx){
                ans += min((ll)n - i, (ll)idx + 1);
                //cout << "i: " << i << "idx: " << idx << "\n";
            }
        }
    }
    for (int i = 0 ; i < n; i++){
        if (a[i] == b[i]){
            ans += (ll)(n - i - 1) * (ll)(n - i)/2LL;
        }
    }
    for (int i = n - 1; i >= 0; i--){
        if (a[i] == b[i]){
            ans += (ll)(i) * (ll)(i + 1)/2LL;
        }
    }
    cout << ans;
}