#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n  >> m;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    if (n == 1){
        cout << a[0];
        return 0;
    }
    int mIndex = 0;
    a[0] = max(a[0], a[1] - m);
    for (int i = 1; i < n - 1; i++){
        a[i] = max(max(a[i + 1] - m, a[i - 1] - m), a[i]);
    }

    a[n - 1] = max(a[n - 1], a[n - 2] - m);
    for (int i = n - 2; i >= 1; i--){
        a[i] = max(max(a[i + 1] - m, a[i - 1] - m), a[i]);
    }
    a[0] = max(a[0], a[1] - m);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    

}