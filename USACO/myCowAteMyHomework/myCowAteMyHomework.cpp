#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    //prefix sums + going backwards
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector <int> nums(n), pfs(n + 1);
    pfs[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        pfs[i + 1] = pfs[i] + nums[i];
    }
    int minNum = INT_MAX;
    float ans = -1;
    vector <int> ansVect;
    for (int i = n - 1; i >= 0; i--){
        minNum = min(nums[i], minNum);
        int val = (pfs[n] - pfs[i + 1]) - minNum;
        int num = (n - i) - 2;
        float tAns = (float) val/num;
        if (i > n - 3){continue;}
        if (ans < tAns){
            ansVect.clear();
            ans = tAns;
            ansVect.push_back(i + 1);
        } else if (ans == num/val){
            ansVect.push_back(i + 1);
        }
    }
    sort(ansVect.begin(), ansVect.end());
    for (int i: ansVect){
        cout << i << "\n";
    }
}