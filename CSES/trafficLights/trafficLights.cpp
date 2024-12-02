#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    cin >> x >> n;
    set <int> lights;
    multiset <int> dist;

    lights.insert(0); 
    lights.insert(x);
    dist.insert(x);

    while (n--){
        int p, ans;
        cin >> p;
        lights.insert(p);
        set<int>::iterator it = lights.lower_bound(p);
        auto nextLight = *next(it); 
        auto prevLight = *prev(it);
        dist.erase(dist.find(nextLight - prevLight));
        dist.insert(nextLight - *it);
        dist.insert(*it - prevLight);
        ans = *(--dist.end());
        cout << ans << " ";

    }
}