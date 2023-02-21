#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector <pair <int, int>> nums(n);
   
    for (int i = 0; i < n; i++){
        cin >> nums[i].first; nums[i].second = i + 1;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++){
        int left = 0, right = n - 1;
        while (right > left){
            if (right == i){right--; continue;}
            if (left == i){left++; continue;}
            if (nums[right].first + nums[left].first + nums[i].first > x){
                right--;
            } else if (nums[right].first + nums[left].first + nums[i].first < x){
                left++;
            } else{
                cout << nums[right].second << " " << nums[left].second << " " << nums[i].second << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}
