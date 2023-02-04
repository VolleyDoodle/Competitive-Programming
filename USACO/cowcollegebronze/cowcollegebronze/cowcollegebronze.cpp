using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
int main()
{
    //two pointers!!!!!
    int maxtut = 0;
    //multiset<int, int> cowtut;
    map <int, int> cowpossible;
    vector <long long> pfs;
    pfs.push_back(0);
    float n, runningSum = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp; //cowtut.insert(tempTution); 
        maxtut = max(maxtut, temp);
        if (cowpossible.count(temp) == 0) {
            cowpossible[temp] = 1; 
        }
        else if (cowpossible.count(temp) > 0) { cowpossible[temp]++; }
        
    }
    int c = 0;
    for (const auto& x : cowpossible) {
        pfs.push_back(pfs[c] + x.second);
        c++;
    }
    c = 0;
    long long ans = 0, tempAns = 0;
    int ansNum;
    for (const auto& x: cowpossible) {
        tempAns = x.first * (pfs[pfs.size() - 1] - pfs[c]);
        if (tempAns > ans) { ansNum = x.first; }
        ans = max(ans, tempAns);
        c++;
    }
    cout << ans << " " << ansNum;
    
    
}

