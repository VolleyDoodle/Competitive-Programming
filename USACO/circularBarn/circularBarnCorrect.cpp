//idk tried some sort of dp solution, basically wrong because it computes the asnwer wrong
#include <bits/stdc++.h>
using namespace std;
const int num = 5 * 1e6 + 2;
int n;
vector <int>  dp(num + 1, 1e7);
vector <vector <int>> primes(4);
bool isPrime[num + 1];
void genPrimes(){

    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    primes[1].push_back(1);
    for (int i = 2; i * i <= num; i++){
        if (isPrime[i]){
            for (int x = i * i; x <= num; x+=i){
                isPrime[x] = false;
            }
            //primes[i%4].push_back(i);
        }
        
    }
    isPrime[1] = true;
    for (int i = 0; i <= num; i++){
        if (isPrime[i]){
            primes[i%4].push_back(i);
        }
    }

}
void calc2(){
    //dp idea essentially
    //dp[i] needs to store the shortest path  to 0
    //how do i find the # of moves for multiples of 4?
    //for the multiples of 4, 
    dp[0] = 0; dp[4] = 2;
    for (int i = 0; i <= num; i+=2){
        dp[i] = i/2;
    }
    for (int i = 0; i <= num; i++){
        if (i%2 != 0){
            auto it = upper_bound(primes[i%4].begin(), primes[i%4].end(), i);
            it--;
            dp[i] = min(dp[i],dp[i - *it] + 1 );
        }
    }
    //dp for multiples of 4 is just a compositive + prime == multi of 4
}
void solve(){

    cin >> n;
    vector <vector <int>> a(n, vector <int>(3));
    for (int i = 0;i < n; i++){
        int temp;
        cin >> temp;
        a[i][0] = dp[temp]; a[i][1] = i; a[i][2] = temp;
        if (a[i][0]%2 == 0) a[i][0]+= 2;
        else if (a[i][0]%2 == 1) a[i][0]++;
    }
    sort(a.begin(), a.end());
    cout << "Farmer " << (a[0][2]%4 == 0 ? "Nhoj" : "John");
    
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    //memset(isPrime, false, sizeof(isPrime));
    genPrimes();
    //cout << "h";
    calc2();

    while (t--){
        solve();
        cout << "\n";
    }
}