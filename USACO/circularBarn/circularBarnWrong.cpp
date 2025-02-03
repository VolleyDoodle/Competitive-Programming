//idk tried some sort of dp solution, basically wrong because it computes the asnwer wrong
#include <bits/stdc++.h>
using namespace std;
const int num = 1e4 + 2;
int n;
vector <int> canUse, dp(num + 1, INT_MAX);
bool isPrime[num + 1];
void genPrimes(){

    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= num; i++){
        if (isPrime[i]){
            for (int x = i * i; x <= num; x+=i){
                isPrime[x] = false;
            }
        }
    }
    isPrime[1] = true;
    for (int i = 0; i <= num; i++) if (isPrime[i]) canUse.push_back(i);

}
void calc2(){
    //dp idea essentially
    //dp[i] needs to store the shortest path  to 0
    //how do i find the # of moves for multiples of 4?
    //for the multiples of 4, 
    dp[0] = 0; dp[4] = 2;
    for (int i = 0; i <= num; i++){
        if (dp[i] == INT_MAX || isPrime[i]) continue;
        for (int pos : canUse){
            if (i + pos > num) break;
            if ((i + pos)%4 == 0 && !isPrime[i]){
                dp[i + pos] = min(dp[i + pos], dp[i] + 1);
            }
            if (i%4 == 0){
                dp[i + pos] = dp[i] + 1;
            }
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
    }
    sort(a.begin(), a.end());
    cout << "Farmer " << (a[0][2]%4 == 0 ? "Nhoj" : "John");
    
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
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