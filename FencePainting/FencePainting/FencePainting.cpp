
#include <iostream>
using namespace std;
int nLine[101];
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i < b; i++) { nLine[i] = 1; }
    for (int i = c; i < d; i++) { nLine[i] = 1; }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        if (nLine[i]) { ans++; }
    }
    cout << ans;
}


