
#include <iostream>
#include <set>
using namespace std;
set <string> t;
void solve(string n, int start) {
    if (start == n.length()) { t.insert(n); return; }
    for (int i = start; i < n.length(); i++) {
        swap(n[start], n[i]);
        solve(n, start + 1);
        swap(n[i], n[start]);
    }
}
int main()
{
    string n;
    cin >> n;
    solve(n, 0);
    cout << t.size() << endl;
    for (auto x : t) {
        cout << x << endl;
    }
}
