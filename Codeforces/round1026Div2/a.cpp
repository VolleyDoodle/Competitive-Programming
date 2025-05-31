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
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        int n, ans = INT_MAX;
        cin >> n;
        int minOdd = -1, maxOdd = -1, minEven = -1, maxEven = -1;
        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0 ; i < n; i++){
            //cin >> a[i];
            if (a[i]%2){
                if (minOdd == -1 || a[minOdd] > a[i]){
                    minOdd = i;
                }
                if (maxOdd == -1 || a[maxOdd] <= a[i]){
                    maxOdd = i;
                }
            } else{
                if (minEven == -1 || a[minEven] > a[i]){
                    minEven = i;
                }
                if (maxEven == -1 || a[maxEven] <= a[i]){
                    maxEven = i;
                }
            }
        }
        /*if (minOdd == -1 && maxOdd != -1){
            ans = min(ans, maxOdd + (n - 1 - maxOdd));
        }
        if (minOdd != -1 && maxOdd == -1){
            ans = min(ans, minOdd + (n - 1 - minOdd));
        }
        if (minEven == -1 && maxEven != -1){
            ans =  min(ans, minEven )
        }
        if (minEven != -1 && maxEven == -1){
            
        }*/
        if (minOdd != -1 && maxOdd != -1){
            ans = min(ans, (minOdd) + (n - 1 - maxOdd));
        } if (minEven != -1 && maxEven != -1){
            ans = min(ans, (minEven) + (n - 1 - maxEven));
        }
        cout << ans << "\n";
    }
}