#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
class cow {
public:
    int pos; char breed;  int pfs;
};
int main()
{
    int n; cin >> n;
    //vector <pair <int, char>> cows;
    set <cow> cows;
    for (int i = 0; i < n; i++) {
        int tPos; char tBreed; cin >> tPos >> tBreed; 
        cow temp; temp.pos = tPos; temp.breed = tBreed; temp.pfs = 0;
        cows.insert(temp);
    }
    //(cows.begin(), cows.end());
    int ans = 0, balance = 0, count = 0;

    
    cout << ans;
}

