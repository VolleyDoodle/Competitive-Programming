#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int n, k, m = 0;
    cin >> n >> k;
    vector <int> berries(n);
    for (int i = 0; i < n; i++){
        cin  >> berries[i];
        m = max(m, berries[i]);
    }
    //baseline assume k > n
    vector <int> stacks(m + 1);
    int ans  = 0;
    for (int bs = 1; bs <= m; bs++){
        //first count number of stacks of bs amount available
        fill(stacks.begin(), stacks.end(), 0);
        for (int i = 0; i < n; i++){
            stacks[bs]+=berries[i]/bs;
            stacks[berries[i] % bs]++;
        }
        if (k/2 > stacks[bs]){
            continue;
        }
        stacks[bs]-=k/2;
        int bCount = 0, index = bs, tans = 0;
        while (index > 0 && bCount < k/2){
            if (stacks[index] > 0){
                bCount++;
                tans +=index;
                stacks[index]--;
            } else{
                index--;
            }
        }
        ans = max(ans, tans);
        

    }
    cout << ans;

}