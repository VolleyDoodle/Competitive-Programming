
#include <iostream>
using namespace std;
int main()
{
    int k, ans = 0;
    int c[4];
    string n;
    cin >> k;
    for (int g = 0; g < k; g++) {
        for (int i = 0; i < 4; i++) { cin >> c[i]; }
        cin >> n;
        for (int i = 0; i < c[0]; i++) { 
            if (n[i] == '0') {
                ans += min(c[1], c[3] + c[2]);
            }
            else if (n[i] == '1') {
                ans += min(c[2], c[3] + c[1]);
            }
        
        }
        cout << ans << endl;
        ans = 0;

    }
}

