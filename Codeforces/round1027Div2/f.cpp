#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
const int maxNum = 1e6;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
vector <int> factors(int num){

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        int x, y, k;
        cin >> x >> y >> k;
        //find prime factorization of x and y
        vector <int> xFactors = factors(x);
        vector <int> yFactors = factors(y);

    }
}