#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    map<int, int> m;
    //ifstream cin("input.in");
    //ofstream fout("output.out");
    int n, tempS, tempE;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tempS >> tempE;
        m[tempS] = 1; m[tempE] = -1;
    }
    int ans = 0, current = 0;
    for (const auto& x : m) {
        //fout << x.first << " " << x.second << endl;
        current = current + x.second;
        ans = max(ans, current);
    }
    cout << ans;
    
}

