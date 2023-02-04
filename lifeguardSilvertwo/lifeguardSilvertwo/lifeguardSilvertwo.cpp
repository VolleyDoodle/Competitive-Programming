
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <climits>
using namespace std;
class guard {
public:
    int time; int cow; //cow number, and start/end time
    bool status; //wether start or end
};

int main()
{
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int n; fin >> n;
    vector <guard> lifeguards;
    vector <int> ids;
    vector <int> guardVal;
    for (int i = 0; i < n; i++) {
        int s, e; fin >> s >> e;
        guard temp; temp.time = s; temp.cow = i; temp.status = true;
        lifeguards.push_back(temp); temp.status = false; temp.time = e;
        lifeguards.push_back(temp);

    }
    sort(lifeguards.begin(), lifeguards.end(), [](const guard& a, const guard& b) { return a.time < b.time; });

    
    set <int> workingCows;
    map <int, long long> aloneTime;
    for (int i = 0; i < n; i++) {
        aloneTime[i] = 0;
    }
    long long fAmt = 0;
    for (int i = 0; i < (2 * n); i++) {
        guard curCow = lifeguards[i];

        if (workingCows.size() > 0) {
            //cows working so get final amount
            fAmt += (curCow.time - lifeguards[i - 1].time);
        }
        if (workingCows.size() == 1) {
            //only 1 cow working!!!!
            aloneTime[*(workingCows.begin())] += (curCow.time - lifeguards[i - 1].time );
        }   
        if (curCow.status) {
            workingCows.insert(curCow.cow);
            //another cow working
        }
        
        if (!curCow.status) {
            //end shift for cow
            workingCows.erase(curCow.cow);
        }
        
    }
    //fout << "famt: " << fAmt << endl;
    long long ans = LONG_MAX;
    for (const auto& time : aloneTime) {
        ans = min(ans, time.second);
    }
    if (ans == LONG_MAX) {
        fout << fAmt;
    }
    else {
        fout << fAmt - ans;
    }
    





}
