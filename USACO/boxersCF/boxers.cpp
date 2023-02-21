#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> nums(n);
    int ans = 0, maxE = 0;
    //bool visited[150002];
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        maxE = max(nums[i], maxE);
    }
    vector <bool> visited(maxE + 2);
    //sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++){
        if (nums[i] != 1 && !visited[nums[i] - 1]){
            visited[nums[i] - 1] = true;
            ans++;
        }
        else if (!visited[nums[i]]){
            visited[nums[i]] = true;
            ans++;
        } else if(!visited[nums[i] + 1]){
            visited[nums[i] + 1] = true;
            ans++;
        }
    }
    cout << ans << "\n";
}
