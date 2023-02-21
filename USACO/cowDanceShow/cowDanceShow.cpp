#include <bits/stdc++.h>
using namespace std;
int n, t;
vector <int> nums;
int ans = INT_MAX;
priority_queue<int, vector <int>, greater <int>> pq;

bool check(int k){
    priority_queue<int, vector <int>, greater <int>> pq;
    pq.push(nums[0]);
    int curCow = 1, curTime = 0;
    
    while (pq.size()){
        while (pq.size() < k && curCow < n){
            pq.push(nums[curCow] + curTime);
            curCow++;
        }
        curTime+= max(0, pq.top() - curTime);
        pq.pop();

    }
    return curTime <= t;
}
int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> t;
    nums.resize(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int r = pow(10, 4), l = 0;
    while (r >= l){
        int mid = l + (r - l)/2;
        if (check(mid)){
            ans = min(ans, mid);
            r = mid - 1;
        } else{
            l = mid + 1;
        }

    }
    cout << ans;
    
}