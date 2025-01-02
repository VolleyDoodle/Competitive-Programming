#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    stack <int> stack;
    
    int n;
    cin >> n;
    vector <int> values(n);
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        values[i] = a;
        while (!stack.empty() && values[stack.top()] >= a){
            stack.pop();
        }
        if (stack.empty()){
            cout << 0;
        } else{
            cout << stack.top() + 1;
        }
        stack.push(i);
        cout << " ";
        
    }
    
}