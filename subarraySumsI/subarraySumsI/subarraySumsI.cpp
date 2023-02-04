#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    //ifstream cin("input.in");
    //ofstream fout("output.out");
    int n, x, num;
    cin >> n >> x;
    vector <int> v;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num + v[i]);
    }
    //for (int g = 0; g <= n; g++) { fout << v[g] << " "; }
    //fout << endl;
    int ans = 0, i = 0, j = 1;
    while (true) {
        //fout << "J: " << j  << " i: " << i << endl;
        //fout << "sum: " << v[j] - v[i] << endl;
        if (v[j] - v[i] == x) { ans++; j++; }
        else if (v[j] - v[i] > x) { //fout << "ran1" << endl; 
            i++; }
        else if (v[j] - v[i] < x) { //fout << "ran2" << endl; 
            j++; }
        if (j > n) { break; }
    }
    cout << ans;
}

