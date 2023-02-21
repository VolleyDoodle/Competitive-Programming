#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
	//cout << n << x;
    vector <pair <int, int>> nums(n);
    for (int i = 0; i < n; i++){ cin >> nums[i].first; nums[i].second = i;}
    sort(nums.begin(), nums.end());
    //two pointers
    int right = 0, left = n - 1;
    while (left > right){
        if (nums[left].first + nums[right].first == x){
            cout << nums[left].second + 1 << " " << nums[right].second + 1 << "\n";
            return 0;
        } else if (nums[left].first + nums[right].first > x){
            left--;
        } else{
            right++;
        }
    }
    cout << "IMPOSSIBLE" << "\n";

}