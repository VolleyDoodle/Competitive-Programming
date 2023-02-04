
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    int n, q;
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    fin >> n >> q;
    vector <int> h(n), g(n), j(n);
    h.push_back(0); g.push_back(0); j.push_back(0);
    int hNum = 0, gNum = 0, jNum = 0;
    for (int i = 0; i < n; i++) {
        int breed_num;
        
        fin >> breed_num;
        if (breed_num == 1) {
            hNum++;
        }
        else if (breed_num == 2) { gNum++; }
        else {
            jNum++;
        }
        h[i + 1] = hNum; g[i + 1] = gNum; j[i + 1] = jNum;
    }
    for (int i = 0; i < q; i++) {
        int a, b; 
        fin >> a >> b;
        a--;
        fout << h[b] - h[a] << " " << g[b] - g[a] << " " << j[b] - j[a] << endl;
    }

}
