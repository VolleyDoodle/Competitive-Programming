#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector <int> frogs(n + 1, 0), count(n + 1, 0);
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp <= n){ frogs[temp]++;}
    }
    for (int j = 1; j <=n; j++){
        for (int i = j; i <= n; i+=j){
            count[i]+=frogs[j];
        }
    }
    auto ans = max_element(count.begin(), count.end());
    cout << *ans << endl;


}
int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}