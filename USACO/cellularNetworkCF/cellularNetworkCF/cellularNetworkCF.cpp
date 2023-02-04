#include <fstream>
#include <map>
#include <vector>
#include <iterator>
#include <iostream> 
#include <cstdio>
//#include <climits>
using namespace std;
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    //now can use standard input!!!
    int n, m; fin >> n >> m;
    map<int, bool> nLine; vector <int> towers;
    nLine[INT_MIN] = true; nLine[INT_MAX] = true;
    int temp;
    for (int i = 0; i < n; i++) {fin >> temp; nLine[temp] = true;}
    for (int i = 0; i < m; i++) { fin >> temp; nLine[temp] = false; towers.push_back(temp); }
    int ans;
    map<int, bool>::iterator it;
    for (int i = 0; i < m; i++) {
        advance()
    }
}

