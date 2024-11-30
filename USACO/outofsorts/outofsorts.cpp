#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> nums(n), sNums(n);
    map <int, int> mNums, smNums;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        sNums[i] = nums[i];
        mNums[nums[i]] = i;
    }
    sort(sNums.begin(), sNums.end());
    for (int i = 0; i < n; i++){
        smNums[sNums[i]] = i;
    }
    int ans = 1;
    for (auto& element : mNums){
        if (element.second > smNums[element.first]) ans = max(ans, (element.second - smNums[element.first]) + 1);
    }
    cout << ans;

}