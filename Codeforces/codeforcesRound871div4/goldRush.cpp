#include <bits/stdc++.h>
using namespace std;
float twoThirds = (float)2/3;
void solve(){

}
int main(){
    int t; 
    
    cin >> t;
    while (t--){
        float n; int m;
        cin >> n >> m;
        float nPrev = n;
        so
        if (n == m){
            cout << "YES" << "\n";
            continue;
        }
        while (true){
            n = n * (twoThirds);
            if (ceilf(n) != n){
                cout << "NO";
                break;
            }
            if (m == nPrev - n || m == n){
                cout << "YES";
                break;
            }
            nPrev = n;    
        }
        cout << "\n";
    }
}
