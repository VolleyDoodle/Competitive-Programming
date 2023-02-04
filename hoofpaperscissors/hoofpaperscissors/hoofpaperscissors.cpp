

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int n;
    fin >> n;
    vector <int> h(n), p(n), s(n);
    h.push_back(0); p.push_back(0); s.push_back(0);
    int hNum = 0, pNum = 0, sNum = 0;
    for (int i = 0; i < n; i++) {
        char t; fin >> t;
        if (t == 'H') { hNum++; }
        else if (t == 'P') { pNum++; }
        else { sNum++; }
        h[i + 1] = hNum; p[i + 1] = pNum; s[i + 1] = sNum;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur_ans = max(h[i], max(p[i], s[i])) + max(h[n] - h[i], max(p[n] - p[i], s[n] - s[i]));
        ans = max(ans, cur_ans);
    }
    fout << ans;

}

