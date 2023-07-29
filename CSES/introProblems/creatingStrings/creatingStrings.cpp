#include <bits/stdc++.h>
using namespace std;
string n;
set <string> created;
void solve(string crStr){
    if (crStr.size() == n.size()){
        created.insert(crStr);
        return;
    }
    for (int i = 0; i < n.size(); i++){
        if (n[i] != '9'){
            char temp = n[i];
            n[i] = '9';
            solve(crStr + temp);
            n[i] = temp;
        }
        
    }
}

int main(){
    
    cin >> n;
    solve("");
    cout << created.size() << "\n";
    for (string e : created){
        cout << e << "\n";
    }
}