#include <bits/stdc++.h>
using namespace std;
const int bigNum = 2 * 1e5 + 2;
vector <bool> visited(bigNum);
int points(vector <int> &pos, int index){
    int n = pos.size() - 1, tAns = 0;
    if (pos[index + 1] < pos[index] && !visited[index + 1]){
        visited[index] = true;
        tAns++;
    }
    if (pos[index - 1] > pos[index] && !visited[index - 1]){
        visited[index] = true;
        tAns++; 
    }
    return tAns;
    
}
int main(){
    int n, m;
    cin >> n >> m;
    vector <int> nums(bigNum), pos(bigNum);
    visited.resize(n + 2);
    
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
        pos[nums[i]] = i;
    }
    int ans = 1;
    for (int i = 0; i <= n - 1; i++){
        if (pos[i + 1] < pos[i]){ans++;}
    }
    pos[0] = -1;
    pos[n + 1] = INT_MAX;
    while (m--){
        fill(visited.begin(), visited.end(), false);
        int p1, p2;
        cin >> p1 >> p2;

        int qAns = (points(pos, nums[p1]) + points(pos, nums[p2]));
        
        swap(pos[nums[p1]], pos[nums[p2]]);
        swap(nums[p1], nums[p2]);
        fill(visited.begin(), visited.end(), false);
        int d = (points(pos, nums[p1]) + points(pos, nums[p2]));
        ans+= (d - qAns);
        cout << ans << "\n";
    }
    
}