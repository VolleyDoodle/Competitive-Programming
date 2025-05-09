#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
//i am so retarteddddd
//retarded level inseanse
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        vector <ll> pos(n + 1, 0), neg(n + 1, 0), nums(n);
        for (ll i = 0; i < n; i++){
            cin >> nums[i];
        }
        for (ll i = 1; i <= n; i++){
            pos[i] = pos[i - 1];
            if (nums[i - 1] > 0) pos[i] += nums[i - 1];
        }
        for (ll i = n - 1; i >= 0; i--){
            neg[i] = neg[i + 1];
            if (nums[i] < 0) neg[i] += nums[i];
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++){
            ans = max(ans, pos[i + 1] + abs(neg[i]));
        }
        cout << ans << "\n";

    }
}