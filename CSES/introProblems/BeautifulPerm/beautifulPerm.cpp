#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string ans = "";
    if (n == 1){cout << 1;}
    else if (n < 4){cout << "NO SOLUTION";}
    else{
        int evenCount = 2;
        while (evenCount <= n){
            cout << evenCount << " ";
            evenCount+=2;
        }
        int oddCount = 1;
        while (oddCount <= n){
            cout << oddCount << " ";
            oddCount+=2;
        }
    }
}