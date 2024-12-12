#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    vector <int> arr(s.size());
    for (int i = 0; i < s.size(); i++){
        arr[i] = s[i] - '0';
    }
    for (int i = 0; i < arr.size(); i++){
        int curMax = arr[i], curIndex = i;
        for (int j  = min((int)arr.size() - 1, i + 8); j >= i; j--){
            if (arr[j] - (j - i) >= curMax){
                curMax = arr[j] - (j - i);
                curIndex = j;
            }
        }
        //now element at curIndex will shift to become element i
        //also have to shift everything right
        int temp1 = arr[i], temp2;
        for (int j = i; j <= curIndex - 1; j++){
            temp2 = arr[j + 1];
            arr[j + 1] = temp1;
            temp1 = temp2;
        }
        arr[i] = curMax;
    }
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i];
    }
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}