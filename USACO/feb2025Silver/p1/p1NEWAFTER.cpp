#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
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
        vector <int> a(n), suff_max(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = n - 1; i >= 0; i--){
            suff_max[i] = suff_max[i + 1];
            suff_max[i] = max(suff_max[i], a[i]);
        }
        multiset<int> ms;
        //this loop to find possible moves forward and then compare
        int mxAmt = 0;
        for (int i = 0; i < n; i++){
            if (ms.size() == 0){
                ms.insert(a[i]);
            }
            else if (a[i] > suff_max[i + 1]){
                //if (a[i] == 93) cout << "PASSED \n";
                auto it = ms.lower_bound(a[i]);
                //below if means everything is already greater, no where to move a[i]
                if (it != ms.begin()){
                    //so now, some elements in prefix are less than a[i], however to be usefull they also need to be greater than suff_max[i + 1]
                    auto it1 = ms.lower_bound(suff_max[i + 1]);
                    /*if (a[i] == 93) cout << "PASSED1 \n";
                    if (it == ms.end() && a[i] == 93) cout << "I KNEW IT\n";
                    if (a[i] == 93) cout <<"SUFF MAX: " << suff_max[i + 1] << "\n";
                    if (a[i] == 91){
                        cout << "FIRST\n";
                        for (auto e : ms){
                            cout << e << " ";
                        }
                        cout << "\n";
                    }*/
                    if (it1 != it){
                        //if (a[i] == 93) cout << "PASSED2 \n";
                        //good can add now and akshally be useful
                        mxAmt = max(mxAmt, a[i]);
                    }
                }
                while (!ms.empty() && *ms.begin() < a[i]){
                    ms.erase(ms.begin());
                }
                ms.insert(a[i]);
            } else{
                while (!ms.empty() && *ms.begin() < a[i]){
                    ms.erase(ms.begin());
                }
                ms.insert(a[i]);
            }
            
        }
        int ignoreIdx = -1;
        for (int i = 0; i < n; i++){
            if (a[i] == mxAmt) ignoreIdx = i;
        }
        //cout << "IGNORE: " << a[ignoreIdx] << "\n";
        vector <int> ans;
        int sz = 0;
        for (int i = 0; i < n; i++){
            if (i == ignoreIdx){
                /*auto it = lower_bound(ans.begin(), ans.end(), a[i], greater<int>());
                ans.insert(it, a[i]);
                sz++;

                break;*/
                continue;
            } else{
                while (sz != 0 && ans[sz - 1] < a[i]){
                    ans.pop_back();
                    sz--;
                }
                ans.push_back(a[i]);
                sz++;
            }
        }
        if (ignoreIdx != -1){
            auto it = lower_bound(ans.begin(), ans.end(), a[ignoreIdx], greater<int>());
            ans.insert(it, a[ignoreIdx]);
            sz++;
        }
        for (int i = 0; i < sz - 1; i++) cout << ans[i] << " ";
        cout << ans[sz - 1];
        cout << "\n";
    }

}