#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n; 
    
    cin >> n;
    //vector <pair <int, char>> cows;

    set <pair<int, char>> gCows;
    for (int i = 0; i < n; i++) {
        int tPos; char tBreed;  cin >> tPos >> tBreed;
        gCows.insert(make_pair(tPos, tBreed));
    }
    long long pfs = 0;
    vector <pair <long long, long long>> nCows;
    for (auto element : gCows) {
        if (element.second == 'G') { pfs++; } else { pfs--; }  nCows.push_back(make_pair(element.first, pfs));
    }
    
    nCows.push_back(pair <int, int>(0, 0));
    
    map <long long, long long[2]> findAns; long long ans = 0;
    for (int i = 0; i < nCows.size() - 1; i++) {
        long long curr = nCows[i].second;
       
        if (findAns.count(curr) == 0) { findAns[curr][0] = nCows[i + 1].first; findAns[curr][1] = -1; }

        else if (findAns.count(curr) > 0) { findAns[curr][1] = max(findAns[curr][1], nCows[i].first); }

    }
    for (const auto &arr : findAns) {
        ans = max(ans, arr.second[1] - arr.second[0]);
    }
    //find multiple in a row
    long long start = (*gCows.begin()).first, end;
    char current = (*gCows.begin()).second;
    //cout << current;
    for (auto element: gCows) {
        if (element.second == current) {//atleast two in a row
            end = element.first; ans = max(ans, end - start);
        }
        else {
            start = element.first; current = element.second;
        }
    }


    cout << ans;
    //int ans = 0, balance = 0, count = 0;


    //cout << ans;
}

