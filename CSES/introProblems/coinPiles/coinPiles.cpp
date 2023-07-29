#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        long long a, b;
        cin >> a >> b;
        if (b > a) swap(a, b);
        /*if (a == 0 && b == 0){
            cout << "YES\n";
            continue;
        }
        if (a == 0 || b == 0){
            cout << "NO\n";
            continue;
        }*/
        //commented out code is extra, as these cases are covered in below if-statement
        if ((a + b)%3 == 0 && a <= 2 * b){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}