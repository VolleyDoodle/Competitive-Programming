#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector <int> b;
        for (int i = 0; i < n - 1; i++){
            if (a[i] == a[i + 1]){
                b.push_back(a[i]);
                i++;
            }
        }
        if (b.size() < 4){
            cout << "NO" << "\n";
        } else{
            cout << "YES" << "\n";
            cout << b[0] << " " << b[1] << " " << b[0] << " " << b[b.size() - 1] << " " << b[b.size() - 2] << " " << b[b.size() - 1] << " " << b[b.size() - 2] << " " << b[1];
            cout << "\n";
        }
    }
    

}