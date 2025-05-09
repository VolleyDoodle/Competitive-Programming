#include <bits/stdc++.h>
 
using namespace std;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int i = 0;
        while (i < n / 2 && s[i] == s[n - i - 1]) ++i;
        n -= 2 * i;
        s = s.substr(i, n);
        int ans = n;
        cout << "s " << s << "\n";
        cout << "size of s " << s.size() << "\n";
        for (int z = 0; z < 2; ++z) {
            int l = 0, r = n;
            while (l <= r) {
                int m = (l + r) / 2;
                vector<int> cnt(26);
                for (int i = 0; i < m; ++i)
                    cnt[s[i] - 'a']++;
                bool ok = true;
                for (int i = 0; i < min(n / 2, n - m); ++i) {
                    char c = s[n - i - 1];
                    if (i < m) {
                        ok &= cnt[c - 'a'] > 0;
                        cnt[c - 'a']--;
                    } else {
                        ok &= (c == s[i]);
                    }
                }
                for (auto x : cnt)
                    ok &= (x % 2 == 0);
                if (ok) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            ans = min(ans, r + 1); 
            reverse(s.begin(), s.end());
        }
        cout << ans << '\n';
    }
}