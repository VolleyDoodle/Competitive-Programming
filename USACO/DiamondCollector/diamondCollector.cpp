#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <int> nums(n), poss;
    for (int i = 0; i < n; i++){ cin >> nums[i];}

    sort(nums.begin(), nums.end());
    int right = 0, left = 0, pAns = 0;
    while (n > right){
        //cout << "ran" << endl;
        if (nums[right] <= nums[left] +k){
            right++; pAns++;
            if (right == n){
                poss.push_back(right - left);
            }
        } else{
            left = right;
            poss.push_back(pAns);
            pAns = 0;
        }
    }
    sort(poss.begin(), poss.end());
    /*for (int i = 0; i < poss.size(); i++){
        cout << poss[i] << " ";
    }*/
    if (n == 1){cout << 1; }
    else{
        cout <<( poss[poss.size() - 1] + poss[poss.size() - 2]);
    }

    

}