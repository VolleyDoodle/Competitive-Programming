#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // cin("input.in");
    //ofstream cout("output.out");
    int n, x, p, temp;
    
    vector <int> v, vp;
    vp.push_back(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> temp; v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        vp.push_back(vp[i] + v[i]);
    }
    for (int i = 0; i < n; i++) {
        //cout << vp[i] << ' ';
    }
    //cout << endl;
    int ans = 0, crr = 0;
    for (int i = 0; i <= n; i++) {
        if (vp[i] > x) { break; }
        ans++;
    }
    cout << ans - 1;
}


