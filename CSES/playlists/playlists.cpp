#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map  <int, int> m;
    int ans = 0, curStart = 0;
    for (int i = 0; i < n; i++){
        int p1;
        cin >> p1;
        if (m.count(p1)){
            ans = max(ans, i - curStart);
            curStart = max(curStart, m[p1] + 1);
        } 
        m[p1] = i;
    }
    ans = max(ans, (n  - curStart));
    cout << ((ans == 0) ? n : ans);

}