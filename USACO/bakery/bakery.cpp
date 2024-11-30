#include <bits/stdc++.h>
using namespace std;
long long n = 0, tc = 0, tM = 0;
class abc{
public:
    long long a, b, c;
};
bool check(long long D, vector <abc> friends){
    long long upBound = min(tc - 1, D), lowBound = max((long long)0, (D - tM) + 1);
    for (const abc& element : friends){   
        upBound = min(upBound, tc - 1);
        lowBound = max(lowBound, (D - tM) + 1);
        if (element.b > element.a){
            //going to affect upperbound
            double formulaVal = (double)(element.c - (element.a * tc) - (element.b * tM) + (element.b * D))/(element.b - element.a);
            upBound = min(upBound, (long long)floor(formulaVal));
        } else if (element.a > element.b){
            double formulaVal = (double)(element.c - (element.a * tc) - (element.b * tM) + (element.b * D))/(element.b - element.a);
            lowBound = max(lowBound, (long long)ceil(formulaVal));
        } else{
            if (0 > (element.c - (element.a * tc) - (element.b * tM) + (element.b * D))){
                return false;
            }
        }

    }
    return (upBound >= lowBound);
}
void solve(){
    cin >> n >> tc >> tM;
    vector <abc> friends(n);
    for (int i = 0; i < n; i++){
        cin >> friends[i]. a >> friends[i].b >> friends[i].c;
    }
    long long ans = -1;
    long long lo = 0, hi = tc + tM - 2;
    while (lo <= hi){
        long long mid = lo + (hi - lo)/2;
        if (check(mid, friends)){
            ans = mid;
            hi = mid - 1;
        } else{
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}
int main(){
    //freopen("bakery.in", "r", stdin);
    //freopen("bakery.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}