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
        int eCount = k/2, bCount = k/2, index = m, tans;
        while(eCount != 0 && index >= 0){
            if (eCount < stacks[index]){
                //endings here
                stacks[index]-=eCount;
                eCount = 0;           
            } else{
                eCount-=stacks[index];
                stacks[index] = 0;
                index--;
            }
        } 
        while(bCount != 0 && index >= 0){
            if (bCount < stacks[index]){
                //endings here
                tans+=index * bCount;
                stacks[index]-=bCount;
                bCount = 0;           
            } else{
                tans+=index * stacks[index];
                bCount-=stacks[index];
                stacks[index] = 0;
                index--;
            }
            
        }
        ans = max(ans, tans);
        

    }
    cout << ans;

}