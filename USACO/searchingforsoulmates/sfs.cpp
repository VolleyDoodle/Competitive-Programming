#include <bits/stdc++.h>
using namespace std;
long long tally = 1, a, b;
long long recurse(long long ans, long long a, long long b){
    if (a == b){return ans;}
    else if (a < b){
        swap(a, b); tally*=-1;
    }
    //now a > b guarentted and tally (+1 or -1) should be tracke properly asw
    if (a%2 == 1){ //if a is odd
        ans++;
        a+=tally;
    }

    if (tally == 1){
        //only decision is to divide by 2
        a/=2;
        return recurse(ans + 1, a, b);
    } else if (tally == -1){
        return min((a - b) + ans, recurse(ans + 1, a/2, b));
    }
}
void solve(){
    tally = 1;
    cin >> a >> b;
    cout << recurse(0, a, b) << "\n";
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}