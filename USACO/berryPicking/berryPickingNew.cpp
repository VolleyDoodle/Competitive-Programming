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
    setIO("berries");
    int n, k;
    cin >> n >> k;
    vector <int> b(n);
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    int totAns = 0;
    for (int i = 1; i <= 1000; i++){
        multiset <int> amts;
        for (int x = 0; x < n; x++){
            amts.insert(b[x]);
        }
        int need = k/2;
        while (need > 0){
            auto it = prev(amts.end());
            if (*it < i){
                break;
            }
            if (need >= (*it)/i){
                need-=(*it)/i;
                amts.erase(it);
                if ((*it)%i != 0) amts.insert((*it)%i);
            } else if (need < (*it)/i){  
                int nit = *it;
                nit -= need * i;
                need = 0;
                amts.erase(it);
                amts.insert(nit);
            }
        }
        if (need > 0) continue;
        need = k/2;
        int curAns = 0;
        while (need > 0 && !amts.empty()){
            auto it = prev(amts.end());
            if (*it <= i){
                curAns+=*it;
                amts.erase(it);
                need--;
            } else{
                if (need >= (*it)/i){
                    need-=(*it)/i;
                    curAns += ((*it)/i) * i;
                    amts.erase(it);
                    if ((*it)%i != 0) amts.insert((*it)%i);
                } else if (need < (*it)/i){  
                    int nit = *it;
                    nit -= need * i;
                    curAns += need * i;
                    need = 0;
                    amts.erase(it);
                    amts.insert(nit);
                }
            }
        }
        totAns = max(totAns, curAns);
    }
    cout << totAns;
}