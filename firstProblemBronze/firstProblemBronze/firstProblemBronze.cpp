
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    //ifstream fin("input.in");
    //ofstream fout("output.out");
    vector <int> cowtut; int maxtut = 0;
    float n, runningSum = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int tempTution; cin >> tempTution; cowtut.push_back(tempTution); 
        maxtut = max(maxtut, tempTution);
        runningSum += tempTution;
    }
    //cout << runningSum << " " << n << endl;
    float exactAvg = runningSum / n;
    //cout << exactAvg;
    int roundAvg = round(exactAvg);
    //cout << roundAvg;
    long long ans = 0, tempAns = 0;
    int ansNum = 1;
    int tut = 1;
    for (int tut = 0; tut <= maxtut; tut++) {
        for (int i = 0; i < n; i++) {
            if (cowtut[i] >= tut) { tempAns += tut; }
        }
        if (tempAns > ans) { ansNum = tut; }
        ans = max(ans, tempAns); tempAns = 0;
    }
    
    
    cout << ans << " " << ansNum;
}

