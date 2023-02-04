
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
class guard {
public:
    int time, cow; //cow number, and start/end time
    bool status; //wether start or end
};

int main()
{   
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int n; fin >> n;
    vector <guard> lifeguards;
    vector <int> guardVal;
    for (int i = 0; i < n; i++) {
        int s, e; fin >> s >> e;
        lifeguards.push_back({ s, i, true });
        lifeguards.push_back({ e, i, true });

    }
    sort(lifeguards.begin(), lifeguards.end());

    vector <int> aloneTime;
    
    
    

}
 
