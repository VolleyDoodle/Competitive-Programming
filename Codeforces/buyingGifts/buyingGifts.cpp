#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <pair <int, int>> a(n), b(n), values(n);
        string s = "";
        for (int i = 0; i < n; i++){
            cin >> a[i].first >> b[i].first;
            a[i].second = i;
            b[i].second = i;
            values[i].first = a[i].first;
            values[i].second = b[i].first;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        set <int> arb;
        multiset <int> personB;
        int bestAns = INT_MAX;
        for (int i = 0; i < n; i++) personB.insert(b[i].first);
        personB.insert(-1e9 - 10);
        for (int i = 0; i < n; i++){
            //do stuff
            //if using i, then erase at personB
            personB.erase(personB.find(values[a[i].second].second));
            //find largest value in personB currently
            int maxVal = *(prev(personB.end()));
            int tempAns = abs(maxVal - a[i].first);

            //in all values before i, is in arbritate
            auto it = arb.upper_bound(a[i].first);
            if (it != arb.end() && *it > maxVal){
                //iterator is greater than current max element for person a
                //but can only use it if greater than maxVal
                tempAns = min(tempAns, abs(*it - a[i].first));
            } if (it != arb.begin() && (*(prev(it)) > maxVal)){
                tempAns = min(tempAns, abs(*(prev(it)) - a[i].first));
            }

            bestAns = min(bestAns, tempAns);
            arb.insert(values[a[i].second].second);
            
        }
        cout << bestAns << "\n";
    }
    
}