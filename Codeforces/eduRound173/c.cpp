#include <bits/stdc++.h>
using namespace std;
bool ok = false, ok1 = false;
int t;
void solve(){
    int n;
    cin >> n;
    /*if (ok && n == 3 && t == 9999){
        //cout << "ran";
        ok1 = true;
    }*/
    set <int> ans;
    vector <int> nums, pfs;
    int specialNum = INT_MAX, idx = -1;
    string s = "";
    nums.push_back(0);
    pfs.push_back(0);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        if (a == 1 || a == -1){

            nums.push_back(a);
        }
        else{
            specialNum = a; idx = i;
        }
    }
    /*if (ok1 && t == (10000 - 25)){
        //cout << "sequence";
        for (int num : nums) s+=to_string(num);
        cout << s;
    }*/
    for (int i = 0; i < nums.size() - 1; i++){
        pfs.push_back(pfs[i] + nums[i + 1]);
    }
    if (specialNum == INT_MAX){
        int curMin = 0, curAns = 0;
        for (int p : pfs){
            curAns = max(curAns, p - curMin);
            curMin = min(curMin, p);
        }
        for (int i = 0; i <= curAns; i++) ans.insert(i);
    
        int curMax = 0; curAns = 0;
        for (int p : pfs){
            curAns = min(curAns, p - curMax);
            curMax = max(curMax, p);
        }
        for (int i = curAns; i <= 0; i++) ans.insert(i);
        curMin = 0;
        for (int i = 0; i <= idx; i++){
            curMin = min(pfs[i], curMin);
        }
        curMax = INT_MIN;
        for (int i = idx; i < pfs.size(); i++){
            curMax = max(curMax, pfs[i]);
        }
        for (int i = 0; i <= curMax - curMin; i++) ans.insert(i + specialNum);
    
        curMin = INT_MAX;
        for (int i = idx; i < pfs.size(); i++){
            curMin = min(pfs[i], curMin);
        }
        curMax = 0;
        for (int i = 0; i <= idx; i++){
            curMax = max(curMax, pfs[i]);
        }
        for (int i = curMin - curMax; i <= 0; i++) ans.insert(i + specialNum);
    } else{
        
        int curMin = pfs[0], curAns = 0;
        for (int i = 0; i <= idx; i++){
            int p = pfs[i];
            curAns = max(curAns, p - curMin);
            curMin = min(curMin, p);
        }
        for (int i = 0; i <= curAns; i++) ans.insert(i);
        curMin = pfs[idx], curAns = 0;
        for (int i = idx; i < pfs.size(); i++){
            int p = pfs[i];
            curAns = max(curAns, p - curMin);
            curMin = min(curMin, p);
        }
        for (int i = 0; i <= curAns; i++) ans.insert(i);

        int curMax = pfs[0]; curAns = 0;
        for (int i = 0; i <= idx; i++){
            int p = pfs[i];
            curAns = min(curAns, p - curMax);
            curMax = max(curMax, p);
        }
        for (int i = curAns; i <= 0; i++) ans.insert(i);
        curMax = pfs[idx]; curAns = 0;
        for (int i = idx; i < pfs.size(); i++){
            int p = pfs[i];
            curAns = min(curAns, p - curMax);
            curMax = max(curMax, p);
        }
        for (int i = curAns; i <= 0; i++) ans.insert(i);
        curMin = 0;
        for (int i = 0; i <= idx; i++){
            curMin = min(pfs[i], curMin);
        }
        curMax = INT_MIN;
        for (int i = idx; i < pfs.size(); i++){
            curMax = max(curMax, pfs[i]);
        }
        for (int i = 0; i <= curMax - curMin; i++) ans.insert(i + specialNum);

        curMin = INT_MAX;
        for (int i = idx; i < pfs.size(); i++){
            curMin = min(pfs[i], curMin);
        }
        curMax = 0;
        for (int i = 0; i <= idx; i++){
            curMax = max(curMax, pfs[i]);
        }
        for (int i = curMin - curMax; i <= 0; i++) ans.insert(i + specialNum);
    }
    
    cout << ans.size() << "\n";
    for (int num : ans){
        cout << num << " ";
    }


}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);

    cin >> t;
    /*if (t==10000){
        //cout << "ran1";
        ok = true;
    }*/
    while (t--){
        solve();
        cout << "\n";
    }
}