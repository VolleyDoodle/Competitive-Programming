#include <bits/stdc++.h>
using namespace std;
/*std::string to_binary(int n) {
    std::string binary = std::bitset<32>(n).to_string(); // 32 bits binary string
    // Remove leading zeros
    binary.erase(0, binary.find_first_not_of('0'));
    return binary.empty() ? "0" : binary; // if the result is empty, return "0"
}*/
void solve() {
    int l, r;
    cin >> l >> r;
    int numbits = sizeof(r) * 8;
    int a, b, c;
    for (int i = numbits - 1; i >= 0; i--){
        if (r & (1 << i) && (l & (1 << i)) == 0){
            //if there is 1 at this bit (in r)
            //and a zero at this bit (in l)
            a = r & (~((1 << i) - 1));
            b = a - 1;
            if (a + 1 <= r){
                c = a + 1;
            } else if (b - 1 >= l){
                c = b - 1;
            }
            break;
        }
    }
    cout << a << " " << b << " " << c;
}
 
signed main() {
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    
 
    while (t--) {
        solve();
        cout << "\n";
    }
}