#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
//i look at shapes, and i become the shapes...
void solve(){
    ll type, num, time;
    cin >> type >> num >> time;
    if (type == 1){
        ll atStart = 2 + 3 * (num - 1);
        atStart-=num;
        ll curLoc = num;
        if (time <= atStart){
            cout << curLoc;
        } else{
            while (time > atStart){
                atStart += curLoc;
                curLoc = (int)(atStart/2);
            }
            cout << atStart - time << "\n";
        }
    } else{
        vector <int> nums;
        for (int i = 0; i < time + 1; i++){
            nums.push_back(i);
            rotate(nums.begin(), nums.begin() + 1, nums.begin() + (int)(i/2) + 1);
        }
        /*for (int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << "\n";*/
        cout << nums[num] << "\n";
    }
    return;

}
//follows 2, 5, 8, 11, 14 (+ 3)
//(0, 0) (2, 1) (5, 2) (8, 3) (11, 4) (14, 5) (17, 6)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    
    int q;
    cin >> q;
    while (q--){
        solve();
    }
}