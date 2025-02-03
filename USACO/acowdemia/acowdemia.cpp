#include <bits/stdc++.h>
using namespace std;
long long n, k, l;
bool check(long long mid, vector <long long>& c){
    long long amt = k * l;
    long long cnt = 0;
    while (cnt < mid){
        if (c[c.size() - cnt - 1] + amt >= mid && k >= (mid - c[c.size() - cnt - 1])){
            amt -= max(0LL, mid - c[c.size() - cnt - 1]);
            cnt++;
        } else{
            return false;
        }
    }
    return true;
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);

    cin >> n >> k >> l;
    vector <long long> c(n);
    for (long long i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    long long left = 0, right = 1e5;
    long long ans = 0;
    while (left <= right){
        long long mid = left + (right - left)/2;
        if (check(mid, c)){
            left = mid + 1;
            ans = mid;
        } else{
            right = mid - 1;
        }
    }
    cout << ans;

}