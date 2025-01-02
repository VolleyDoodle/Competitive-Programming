#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> visited(5, false);
    for (int i = 0; i < 4; i++){
        int t;
        cin >> t;
        visited[--t] = true;
    }
    for (int i = 0; i < 5; i++){
        if (!visited[i]) cout << i + 1;
    }
}