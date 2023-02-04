#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q; cin >> n >> q;
    unordered_map<int, int> cows; int b_i, pfs = 0;
    for (int i = 0; i < n; i++) {
        cin >> b_i; pfs += b_i; cows[i + 1] = pfs;
    }

    int t_i;
    for (int i = 0; i < q; i++) {
        cin >> t_i;
        cout << cows[t_i] << endl;
    }
}
