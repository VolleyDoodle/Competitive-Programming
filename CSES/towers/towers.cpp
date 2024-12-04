#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    multiset <int> towers;
    while (n--){
        int t;
        cin >> t;
        auto it = towers.upper_bound(t);
        if (it == towers.end()){
            towers.insert(t);
        } else{
            towers.erase(it);
            towers.insert(t);
        }
    }
    cout << towers.size();
}