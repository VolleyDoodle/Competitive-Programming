#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int type, num, time;
    cin >> type >> num >> time;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("brute");
    int q;
    cin >> q;
    vector <int> nums;
    for (int i = 0; i < q; i++){
        nums.push_back(i);
        rotate(nums.begin(), nums.begin() + 1, nums.begin() + (int)(i/2) + 1);
        cout << "time: " << i << " | ";
        for (int & num: nums){
            cout << num << " ";
        }
        cout << "\n";

    }
}