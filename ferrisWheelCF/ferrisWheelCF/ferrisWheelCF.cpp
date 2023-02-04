#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    //ifstream fin("input.in");
    //ofstream fout("output.out");
    int n, x, temp;
    cin >> n >> x;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        cin >> temp; v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int i = 0, p = n - 1, ans = 0;
    while (i <= p) {
        //fout << "ran";
        if (i == p) { ans++; break; }
        else if(v[i] + v[p] > x) { //fail
            p--; ans++;
        }
        else if (v[i] + v[p] <= x) { //success
            i++; p--; ans++;
        }
    }
    cout << ans;
}

