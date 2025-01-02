#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    long long k, m, n;
    cin >> k >> m >> n;
    vector <pair <long long, long long>> patches(k);
    vector <long long> locs(m);

    for (long long i = 0; i < k; i++){
        cin  >> patches[i].first >> patches[i].second;
    }
    for (long long i = 0; i < m; i++){
        cin >> locs[i];
    }
    sort(patches.begin(), patches.end());
    locs.push_back(1e10);
    locs.push_back(-1e10);
    sort(locs.begin(), locs.end());
    
    vector <pair <long long, long long>> interval;
    vector <long long> amts;
    long long curAmt = 0;
    long long curLocIdx = 0;
    for (long long i = 0; i < k; i++){
        if (locs[curLocIdx] <= patches[i].first){
            
            i--;
            
            curLocIdx++;
            if (interval.size() == 0) continue;
            long long sz = locs[curLocIdx - 1] - locs[curLocIdx - 2];
            sz/=2;

            long long totAmt = 0;
            for (long long i = 0; i < interval.size(); i++){
                totAmt+=interval[i].second;
            }
            long long maxOneCow = 0, curMaxOneCow = 0;
            long long left = 0, right = 0;
            maxOneCow = interval[0].second;
            curMaxOneCow = interval[0].second;
            while (left <= right && right <= interval.size() - 1){
                
                if (interval[right].first - interval[left].first < sz){
                    maxOneCow = max(maxOneCow, curMaxOneCow);
                    right++;
                    if (right == interval.size()) break;
                    curMaxOneCow += interval[right].second;
                } else{
                    curMaxOneCow -= interval[left].second;
                    left++;
                }
            }
            amts.push_back(maxOneCow);
            amts.push_back(totAmt - maxOneCow);

            interval.clear();
        } else{
            interval.push_back(patches[i]);
        }
    }
    long long endIntAmt = 0;
    for (long long i = 0; i < interval.size(); i++){
        endIntAmt +=interval[i].second;
    }
    amts.push_back(endIntAmt);
    //amts.push_back(curAmt);
    sort(amts.begin(), amts.end());
    long long ans = 0;
    for (long long i = amts.size() - 1; i >= max((long long)0, (long long)amts.size() - n); i--){
        ans+=amts[i];
    }
    cout << ans;
}