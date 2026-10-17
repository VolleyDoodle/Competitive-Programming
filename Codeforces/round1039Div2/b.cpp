#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string pre){
    freopen((pre + ".in").c_str(), "r", stdin);
    freopen((pre + ".out").c_str(), "w", stdout);
}

void solve(){
    int n;
    cin >> n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int left = 0, right = n - 1;
    string output = "";
    //do less, more, less more
    bool lessmore = 1;
    while (left < right){
        if (nums[left] < nums[right]){
            if (lessmore) {
                output+="L";
                left+=1;
                output+="R";
                right-=1;
                lessmore = !lessmore;
            } else{
                output+="R";
                right-=1;
                output+="L";
                left+=1;
                lessmore = !lessmore;
            }   
        } else{
            if (!lessmore) {
                output+="L";
                left+=1;
                output+="R";
                right-=1;
                lessmore = !lessmore;
            } else{
                output+="R";
                right-=1;
                output+="L";
                left+=1;
                lessmore = !lessmore;
            }   
        }
    }
    if (left == right){
        cout << output + "R\n";
    } else{
        cout << output + "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}