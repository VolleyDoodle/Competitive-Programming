#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int m, s;
    cin >> m >> s;
    int count = m;
    vector <int> ans;
    //least num
    //note that biggest num is backwards least num
    for (int i = 0; i < m; i++){
        count--;
        if (s - (count * 9) <= 0){
            ans.push_back(1); s--;
        } else{
            ans.push_back(s - (count * 9)); s-=s - (count * 9);
        }
    }
    for (int i = 0; i < m; i++){
        cout << ans[i];
    }
    cout << " ";
    for (int i = m - 1; i >= 0; i--){
        cout << ans[i];
    }

}