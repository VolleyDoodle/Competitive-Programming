using namespace std;
#include <set>
#include <iostream>
#include <fstream>
int main()
{
    int n, m;
    multiset <int> hs;
    //ifstream cin("ct.in");
    //ofstream cout("ct.out");
    cin >> n >> m;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num; hs.insert(num);
    }
    int mp;
    /*for (auto element : hs) {
        cout << element << " ";
    }*/
    //cout << endl;
    //auto it = hs.upper_bound
    for (int i = 0; i < m; i++) {
        cin >> mp;
        // << mp << " ";
        auto it = hs.upper_bound(mp);
        //cout << *it << " ";
        
        if (it == hs.begin()) { cout << -1 << endl; }
        else {
            it = (--it);
            cout << *(it) << endl;
            hs.erase(it);
        }
        //cout << *(--it) << endl;
    }
}

