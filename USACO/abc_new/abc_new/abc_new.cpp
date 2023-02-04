

#include <iostream>
using namespace std;
#include <algorithm>
int main()
{
    int a[7];
    for (int i = 0; i < 7; i++) { cin >> a[i]; }
    sort(a, a + 7);
    cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1];
}
