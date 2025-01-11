#include <bits/stdc++.h>
 
using i64 = long long;
std::string to_binary(int n) {
    std::string binary = std::bitset<32>(n).to_string(); // 32 bits binary string
    // Remove leading zeros
    binary.erase(0, binary.find_first_not_of('0'));
    return binary.empty() ? "0" : binary; // if the result is empty, return "0"
}
void solve() {
    int l, r;
    std::cin >> l >> r;
    std::cout << to_binary(l) << std::endl;
    std::cout << to_binary(r) << std::endl;
    int k = 31 - __builtin_clz(l ^ r);
    int a = l | ((1 << k) - 1), b = a + 1, c = (a == l ? r : l);
    std::cout << a << " " << b << " " << c << "\n";
    std::cout << to_binary(a) << std::endl;
    std::cout << to_binary(b) << std::endl;
    std::cout << to_binary(c) << std::endl;
}
 
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
 
    while (t--) {
        solve();
    }
}