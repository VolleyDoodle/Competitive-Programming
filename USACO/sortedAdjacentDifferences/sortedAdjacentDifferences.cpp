#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector <int> nums(n);
        for (int i = 0; i < n; i++){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        int mid = n/2, i = 0;
        while (true){
            cout << nums[mid + i] << " ";
            if (i >= 0){
                i++;
                i*=-1;
            } else{
                i*=-1;
            }
            if (mid + i < 0 || n - 1 < mid + i){
                break;
            }
        }
        cout << "\n";
    }
}