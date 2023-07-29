#include <bits/stdc++.h>

using namespace std;
map<string, bool> dict;
string bigString;
int main(){
    freopen("allWords.txt", "r", stdin);
    for (int i = 0; i < 10; i++){
        string temp;
        cin >> temp;
        dict[temp] = true;
    }
    
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    
    cin >> bigString;
    cout << bigString;
    while (true){
        
    }
}