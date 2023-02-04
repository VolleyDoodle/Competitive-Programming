#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class movie {
public:
    int start;
    int end;
};
bool vcmp(const movie& a, const movie& b) {
    return a.end < b.end;
}
int main()
{
    vector <movie> v;
    // cin("input.in");
    //ofstream cout("output.out");
    int n,s , e; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        movie temp; temp.start = s; temp.end = e;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), vcmp);
    int curEnd = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (curEnd <= v[i].start) {
            curEnd = v[i].end;
            ans++;
        }
    }
    cout << ans;
}

