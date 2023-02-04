#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    //ifstream fin("input.in");
    //ofstream fout("output.out");
    int n, t;
    cin >> n >> t;
    vector <int> v;
    vector <int> vs;
    vs.push_back(0);
    int temp;    int curr = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp; v.push_back(temp); vs.push_back(temp + vs[i]);
    }
    for (int i = 0; i <= n; i++) {
        //fout << vs[i] << " ";
    }
    int ans = 0;
    int i = 0, p = 1;
    //fout << endl;
    while (true) {
        //fout << "i: " << i << " p: " << p << endl;
        if (vs[p] - vs[i] > t) { //fout << "ran1" << endl; 
        i++; } //too much
        else if (vs[p] - vs[i] <= t) { //fout << "ran2" << endl; 
            ans = max(ans, p - i); 
            p++;
           }//too less
        if (p == n + 1) { break; }

    } 
    cout << ans;
}

