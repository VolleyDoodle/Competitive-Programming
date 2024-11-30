#include <bits/stdc++.h>
using namespace std;
long long x1, Y1, x2, y2, n;
string dir;
vector <long long> NS, EW;
bool check(long long maxDays){
    long long nX2 = x2, nY2 = y2;
    //makes new x2, y2 cords with the wind
    nX2 -= (maxDays/n) * (EW[n - 1]);
    if (maxDays%n != 0){
        nX2 -= EW[maxDays%n - 1];
    }
    nY2 -= (maxDays/n) * NS[n - 1];
    if (maxDays%n != 0){
        nY2 -= NS[maxDays%n - 1];
    }
    //now you have maxDays time to go from x1, Y1 to nX2, nY2
    return maxDays >= abs(nX2 - x1) + abs(nY2 - Y1);
}
int main(){
    cin >> x1 >> Y1;
    cin >> x2 >> y2;

    cin >> n;
    cin >> dir;
    NS.resize(n, 0); EW.resize(n, 0);
    //North = +1, South = -1, East = +1, West = -1
    for (int i = 0; i < n; i++){
        if (i){
            NS[i] = NS[i - 1];
            EW[i] = EW[i - 1];
        }
        if (dir[i] == 'U' || dir[i] == 'D'){
            NS[i] +=  (dir[i] == 'U' ? 1 : -1);
        }
        else if (dir[i] == 'L' || dir[i] == 'R'){
            EW[i] += (dir[i] == 'R' ? 1 : -1);
        }
    }
    long long ans = -1;
    long long lo = 1, hi = 1e18;
    while (lo <= hi){
        long long mid = lo + (hi - lo)/2;
        if (check(mid)){
            hi = mid - 1;
            ans = mid;
        } else{
            lo = mid + 1;
        }
    }
    cout << ans;
}