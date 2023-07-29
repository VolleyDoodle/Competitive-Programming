#include <bits/stdc++.h>
using namespace std;

int main(){
    string codeforces = "codeforces";
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int ans = 0;
        string temp; cin >> temp;
        for (int x = 0; x < 10; x++){
            if (temp[x] != codeforces[x]){
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
