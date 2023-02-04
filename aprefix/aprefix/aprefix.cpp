

#include <iostream>
using namespace std;
int main()
{
    int n, ans= 0;
    char a[200001];
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    for (int i = 0; i < n - 1; i = i + 2) {
        if (a[i] == a[i + 1]) {
            if (a[i] == 'a') { a[i + 1] = 'b'; }
            else if (a[i] == 'b') { a[i + 1] = 'a'; }
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) { cout << a[i]; }
}


