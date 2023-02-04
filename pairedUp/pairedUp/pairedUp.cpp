#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
class a {
public:
    int num, output;
};
bool vcmp(const a & c, const a & b) {
    return c.output < b.output;
}


int main()
{
    //greed solution: pair min cow with max cow to minimize amount
    //takes too much time 10^9
    //ifstream cin("pairup.in");
    //ofstream cout("pairup.out");
    int m = 0, n; cin >> n;
    int numC, outputC;
    vector <a> v;
    for (int i = 0; i < n; i++) {
        cin >> numC >> outputC;
        a temp; temp.num = numC; temp.output = outputC;
        m += numC; v.push_back(temp);
    }
    sort(v.begin(), v.end(), vcmp);
    int i = 0, j = n - 1, mPairs, ans = 0;
    while (i <= j) {
        mPairs = min(v[i].num, v[j].num);
        ans = max(ans, v[j].output + v[i].output);
        if (i == j) { v[i].num -= mPairs;}
        else { v[i].num -= mPairs; v[j].num -= mPairs; }
        if (v[j].num == 0) { j--; } if (v[i].num == 0) { i++; }


    }
    cout << ans;
}

