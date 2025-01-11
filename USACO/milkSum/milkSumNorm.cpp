//when deciding to be sped vs not sped
//be sped
//this problem is so fucking stupid and i am being sped as well
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
        ll i, j;
        cin >> i >> j;
        ll tempVal = nums[idx[i]].f, tempIdx = idx[i];
        auto it = upper_bound(nums.begin(), nums.end(), make_pair(j, tempIdx));
        int idxN = it - nums.begin();
        
        if (tempVal > j){
            cAns -= tempVal * tempIdx;
            //smaller value than replaced
            //so idxN should be less than tempIdx
            cAns += pfs[tempIdx - 1] - pfs[idxN - 1];
            cAns += j * idxN;
        } else if (tempVal < j){
            cAns -= tempVal * tempIdx;
            cAns -= pfs[idxN - 1] - pfs[tempIdx];
            cAns += j * (idxN - 1);
        }
        cout << cAns << "\n";
        
        
    }

    
}