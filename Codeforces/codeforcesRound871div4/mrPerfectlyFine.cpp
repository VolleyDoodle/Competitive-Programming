#include <bits/stdc++.h>
using namespace std;

int leastNum(vector <int> nums){
    int least = INT_MAX;
    for (int i = 0; i < nums.size(); i++){
        least = min(least, nums[i]);
    }
    return least;
}
void solve(){
    int n; cin >> n;
    
    vector <int> skillOne, skillTwo, bothSkills;
    for (int i = 0; i < n; i++){
        int mi; string si;
        cin >> mi >> si;
        if (si[0] == '1' && si[1] == '0'){
            skillOne.push_back(mi);
        } else if (si[1] == '1' && si[0] == '0'){
            skillTwo.push_back(mi);
        } else if (si[0] == '1' && si[1] == '1'){
            bothSkills.push_back(mi);
        }
    }
    int oneLeast = leastNum(skillOne), twoLeast = leastNum(skillTwo), bothLeast = leastNum(bothSkills);
    if ((oneLeast == INT_MAX || twoLeast == INT_MAX)){
        if (bothLeast == INT_MAX){
            cout << -1;
            return;
        }
        else{
            cout << bothLeast;
            return;
        }
    }
    if (bothLeast == INT_MAX){
        
        cout << oneLeast + twoLeast;
        return;
    }
    cout << min(bothLeast, oneLeast + twoLeast);


}
int main(){

    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}