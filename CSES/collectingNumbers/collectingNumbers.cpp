#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> nums(n), pos(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        pos[nums[i] - 1] = i;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++){
        if (pos[i + 1] < pos[i]){ans++;}
    }
    cout << ans + 1;
}