#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
int t;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
bool check(vector <int>& a, vector <int>& curScore, int k){
    int cur = k;
    vector <int> minScore(a.size()), minSuffix(a.size() + 1, INT_MAX);
    minSuffix[a.size()] = k;
    for (int i = a.size() - 1; i >= 0; i--){
        if (a[i] >= cur){
            cur--;
            minScore[i] = cur;
        } else if (a[i] < cur){
            cur++;
            minScore[i] = cur;
        }
        minSuffix[i] = min(minSuffix[i + 1], minScore[i]);
    }
    //int curMax = 0;
    if (minSuffix.size() >= 2 && 0 >= minSuffix[1]){
        return true;
    }
    for (int i = 1; i < a.size(); i++){
        //curMax = max(curMax, curScore[i - 1]);
        if (curScore[i - 1] >= minSuffix[i + 1]){
            return true;
        }
    }
    if (a.size() >= 2 && curScore[a.size() - 2] >= k){
        return true;
    }
    return false;
}
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> curScore(n, 0);
    int cur = 0;
    for (int i = 0;i < n; i++){
        cin >> a[i];
        if (a[i] > cur){
            cur++;
            curScore[i] = cur;
        } else if (a[i] < cur){
            cur--;
            curScore[i] = cur;
        }
    }
    /*if (t == 49813 - 58){
        string st = "";
        for (int i = 0; i < n; i++){
            st += to_string(a[i]);
        }
        cout << st;
    }*/
    int r = n + 1, l = 0;
    int ans = 0;
    while (r >= l){
        int mid = l + (r - l)/2;
        if (check(a, curScore, mid)){
            ans = max(ans, mid);
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");

    cin >> t;
    
    while (t--){
        solve();
        cout << "\n";
    }
}