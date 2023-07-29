#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector <int> odd, even;
    cin >> n;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        temp%2 == 1 ? odd.push_back(i + 1) : even.push_back(i + 1);
        if (odd.size() + even.size() >= 3){
            if (odd.size() == 1){cout << odd[0]; break;}
            if (even.size() == 1) {cout << even[0]; break;}
            
        }
    }

}