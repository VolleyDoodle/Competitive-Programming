#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    map <string, int> database;
    for (int i = 0; i < n; i++){
        string temp; cin >> temp;
        database[temp]++;
        database[temp] >= 2 ? cout << temp << database[temp] - 1 : cout << "OK";
        cout << "\n";
    }
}