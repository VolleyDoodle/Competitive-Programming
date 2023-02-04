
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int n, x, num;
    bool done = false;;
    cin >> n >> x;
    map <int, int> m;
    for (int i = 0; i < n; i++){
        cin >> num;
        if (m.count(x - num)) { cout << m[x - num] + 1 << ' ' << i + 1; done = true; exit(0); }
        m[num] = i;
    }
    cout << "IMPOSSIBLE";
    
}

