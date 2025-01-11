#include <bits/stdc++.h>
using namespace std;
//sooo
//got algorithm right and everything
//just my time complexity (theoritcal) was wrong
//because harmonic series converges to log n
void solve(){
    long long n, m;
    cin >> n >> m;
    vector <long long> a(n), b(m), canSolve(m, 0);

    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < m; i++) cin >> b[i];
    long long kVal = a[0];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    //for contestants can ignore all of them that are less than kevin
    //because kevin will always be equal or better than them
    //any problems that everyone solves or no one solves -> no rankings change (Kevin remains first)
    //so find total # of those type of problems
    //stupid implementation problem ;(
    long long s = upper_bound(b.begin(), b.end(), kVal) - b.begin();
    long long e = b.end() - upper_bound(b.begin(), b.end(), a[n - 1]);
    //now in a, only particpants better than kevin
    //in b, only problems that kevin cannot solve
    //alright canSolve stores for each problem, how many people can solve it
    for (long long i = 0; i < m; i++){
        canSolve[i] = a.end() - (lower_bound(a.begin(), a.end(), b[i]));
    }
    for (long long i = 1; i <= m; i++){
        long long cs = s + m%i;
        long long contests = m/i - (s + e)/i;
        long long ans = (s + e)/i; 
        //c problems that no one/everyone an do, each contest has i problems, so c/i contests where kevin ranks 1
        //there are still (s + e)% i problems left to use
        //cs+= (s + e)%i;
        for (long long x = 0; x < contests; x++){
            ans += canSolve[cs] + 1;
            cs+= i;
        }
        cout << ans << " ";
    }

}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    long long t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}