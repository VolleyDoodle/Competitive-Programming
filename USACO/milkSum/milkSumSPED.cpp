#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    ll n;
    cin >> n;
    vector <pair <ll, ll>> nums(n + 1, {0, 0});
    vector <ll> pfs(n + 1, 0);
    vector <ll> idx(n + 1, 0);
    ll ans = 0;
    for (ll i = 1; i <= n; i++){
        cin >> nums[i].f;
        nums[i].s = i;
        //pfs[i] = nums[i];
    }
    sort(nums.begin(), nums.end());
    //sort(pfs.begin(), pfs.end());
    for (ll i = 1; i <= n; i++){
        pfs[i]+= pfs[i - 1] + nums[i].f;
        idx[nums[i].s] = i;
        ans+=nums[i].f * i;
    }
    ll q;
    cin >> q;
    for (ll y = 0; y < q; y++){
        //sped ahh, sorting takes n log n, not log n :(
        ll cAns = ans;
        ll ai, j;
        cin >> ai >> j;
        ll tempVal = nums[idx[ai]].f, tempIdx = idx[ai];
        nums[idx[ai]].f = j;

        sort(nums.begin(), nums.end());
        ll idxN = lower_bound(nums.begin(), nums.end(), pair<ll, ll>{j, ai}) - nums.begin();

        cAns -= tempVal * tempIdx;
        //og pos is idx[ai], new pos is idxN
        if (j == tempVal){
            cout << cAns << "\n";
        } else if (j > tempVal){
            //means greater val replaced past val
            //so idxN is greater than nums[idx[ai]]
            cAns -= pfs[idxN] - pfs[idx[ai]];
            cAns += j * idxN;
            cout << cAns << "\n";
        } else{
            //lesser val replaced past val
            //so nums[idx[ai]] > idxN
            cAns += pfs[idx[ai] - 1] - pfs[idxN - 1];
            cAns += j * idxN;
            cout << cAns << "\n";
        }
        nums[idxN].f = tempVal;
        sort(nums.begin(), nums.end());
        
    }

    
}