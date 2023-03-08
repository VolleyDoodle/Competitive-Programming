#include <bits/stdc++.h>
using namespace std;
class fr{
    public:
        int a, b, c;
};

void solve(){
    int n, tc, tm; cin >> n >> tc >> tm;
    int tct = tc, tmt = tm;
    vector <fr> friends(n);
    int ans = 0, ans1 = 0, sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++){
        int a, b , c;
        //cin >> a >> b >> c;
        //sumA+=a; sumB+=b;
        cin >> friends[i].a >> friends[i].b >> friends[i].c;
        sumA+=friends[i].a; sumB+=friends[i].b;
    
        
    }
    int l = 0, r = tc;
    while (r >= l){
        int mid = l + (r - l)/2;
        //set mid as new cookie rate
        if (check(mid)){
            ans = min(ans, mid +)
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    cout <<  ans1 << '\n';


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        solve();
    }
}