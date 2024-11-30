#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <string> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(),[](
        const string& a, const string& b){
            return a + b < b + a;
        });
    for (int i = 0; i < n; i++){
        cout << arr[i];
    }
    //cout << 'h';
}