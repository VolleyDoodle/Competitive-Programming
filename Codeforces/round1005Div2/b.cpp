#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <int> nums(n);
        set <int> dis, notdis;
        for (int i = 0; i < n; i++){
            cin >> nums[i];
            if (notdis.count(nums[i])){
                continue;
            } else if (dis.count(nums[i])){
                dis.erase(nums[i]);
                notdis.insert(nums[i]);
            } else{
                dis.insert(nums[i]);
            }
        }
        //dis.size() = # of distinct elements
        int aL = -1, aR = -1;
        for (int i = 0; i < n; i++){
            bool inLoop = false;
            int curL = -1, curR = -1;
            if (dis.count(nums[i])) curL = i;
            while (i < n && dis.count(nums[i])){
                inLoop = true;
                i++;
                
            }
            if (inLoop){
                curR = i - 1;
                i--;
            }
            if (aL == -1 || (curR - curL) > aR - aL){
                aL = curL;
                aR = curR;
            }
        }
        if (aL == -1) cout << 0;
        else{
            cout << aL + 1 << " " << aR + 1; 
        }
        cout << "\n";
    }

}