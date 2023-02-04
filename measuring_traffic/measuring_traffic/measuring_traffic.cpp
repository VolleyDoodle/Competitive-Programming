// measuring_traffic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n;
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");
    fin >> n;
    string trafficMode[100];
    int minPos[100], maxPos[100];
    int minAns = -10000001, maxAns = 10000001;
    for (int i = 0; i < n; i++) {
        fin >> trafficMode[i] >> minPos[i] >> maxPos[i];
    }
    //find start value
    for (int i = n - 1; i >= 0; i--) {
        if (trafficMode[i] == "none") { minAns = max(minAns, minPos[i]); maxAns = min(maxAns, maxPos[i]); }
        if (trafficMode[i] == "on") { minAns -= maxPos[i]; maxAns -= minPos[i]; }
        if (trafficMode[i] == "off") { minAns += minPos[i]; maxAns += maxPos[i]; }
    }
    fout << max(0, minAns) << " " << max(0, maxAns) << endl;
    //find end value
    minAns = -10000001, maxAns = 10000001;
    for (int i = 0; i < n; i++) {
        if (trafficMode[i] == "none") { minAns = max(minAns, minPos[i]); maxAns = min(maxAns, maxPos[i]); }
        if (trafficMode[i] == "on") { minAns += minPos[i]; maxAns += maxPos[i]; }
        if (trafficMode[i] == "off") { minAns -= maxPos[i]; maxAns -= minPos[i]; }
    }
    fout << max(0, minAns) << " " << max(0, maxAns);
    
    
    
}
