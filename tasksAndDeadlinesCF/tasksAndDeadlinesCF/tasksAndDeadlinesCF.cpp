#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class tks {
public:
    int duration, deadline;
};
bool vcmp(const tks& a, const tks& b) {
    return a.duration < b.duration;
}
int main()
{
    //ifstream fin("input.in");
    //ofstream fout("output.out");
    int n, dn, de; cin >> n;
    vector <tks> v;
    for (int i = 0; i < n; i++) {
        cin >> dn >> de;
        tks temp; temp.duration = dn; temp.deadline = de;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), vcmp);
    long long ans = 0, current = 0;
    for (int i = 0; i < n; i++) {
        current += v[i].duration;
        ans += v[i].deadline - current;
    }
    cout << ans;
 
}


