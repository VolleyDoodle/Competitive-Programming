#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
vector <int> genF(int x){
    vector <int> gen;
    for (int i = 1; i < sqrt(x) + 1; i++){
        if (x%i == 0){
            gen.push_back(i);
            gen.push_back(x/i);
            gen.push_back(-1 * i);
            gen.push_back(-1 * x/i);
        }
    }
    return gen;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> a(n), b(m);
    ll aSum = 0, bSum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        aSum+=a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
        bSum+=b[i];
    }
    //og grid = aSum * bSum
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ogVal = aSum * bSum, curVal = aSum * bSum;
    while (q--){
        int x;
        cin >> x;
        bool good = false;
        vector <int> factors = genF(abs(x));
        for (int factor : factors){
            //pretend to change this value
            //basically just saw the new aSum is this
            //and binary search on a[i] to see if possible
            if (binary_search(a.begin(), a.end(), aSum - factor)){
                curVal = factor * bSum;
                if (factor == 0){
                    if (x == 0) good = true;
                    continue;
                }
                int other = x/factor;
                //bSum has to be equal to other now
                
                if (binary_search(b.begin(), b.end(), bSum - other)){
                    good = true;
                }

            }
            curVal = ogVal;
        }
        cout << (good ? "Yes" : "No");
        cout << "\n";
    }
}