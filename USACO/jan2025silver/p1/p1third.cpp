#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll bigNum = 5 * 1e5 + 1; //5 * 1e5 + 1;
ll check(vector <ll>& a, vector <ll>& b){
    ll sum = 0;
    for (ll i = 0; i < a.size(); i++){
        sum += (a[i] == b[i]);
    }
    return sum;
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    ll n, ans = 0;
    cin >> n;
    vector <ll> a(n), b(n), ca(n);
    vector <vector <ll>> graph(bigNum);
    vector <vector <ll>> pfs(bigNum, vector <ll>(1, 0));
    for (ll i = 0; i < n; i++){
        cin >> a[i];
        ca[i] = a[i];
    }
    //n(n - 1)/2 somehtiing is not affectd
    //ll amt = n * (n - 1)/2;
    for (ll i = 0; i < n; i++){
        cin >> b[i];
        //if (b[i] == a[i]) continue;
        graph[b[i]].push_back(i);
    }
    //tomake pfs should be 1e5 + 1e5
    for (ll i = 0; i < bigNum; i++){
        for (ll j = 0; j < graph[i].size(); j++){
            pfs[i].push_back(graph[i][j] + pfs[i][j]);
        }
    }
    for (ll i = 0; i < n; i++){
        
        //ts might be so friggin annoying to implement
        //count case where a[i] == b[i] sepereately
        auto it = lower_bound(graph[a[i]].begin(), graph[a[i]].end(), i);
        if (it != graph[a[i]].begin()){
            //it--;
            auto it2 = lower_bound(graph[a[i]].begin(), it, n - i - 1);
            ll other = it2 - graph[a[i]].begin();
            ans+= pfs[a[i]][other] + other;
            ans += (n - i) * distance(it2, it);
        }
        if (it != graph[a[i]].end() && *it == i){
            it++;
        }
        if (it != graph[a[i]].end()){
            
            auto it2 = lower_bound(it, graph[a[i]].end(), n - i - 1);
            ll amt = (pfs[a[i]].size() - 1) - (it2 - graph[a[i]].begin());
            ll other = it2 - graph[a[i]].begin();
            ans += amt * (n) - (pfs[a[i]][pfs[a[i]].size() - 1] - pfs[a[i]][other]);
            ans += (i + 1) * (distance(it, it2));
        }
        
    }
    //these two just count when this is unaffected
    for (ll i = 0; i < n; i++){
        if (a[i] != b[i]) continue;
        ans += min(n - i, (ll)i + 1LL);
    }
    for (ll i = 0 ; i < n; i++){
        if (a[i] == b[i]){
            ans += (ll)(n - i - 1) * (ll)(n - i)/2LL;
        }
    }
    for (ll i = n - 1; i >= 0; i--){
        if (a[i] == b[i]){
            ans += (ll)(i) * (ll)(i + 1)/2LL;
        }
    }
    cout << ans;
}