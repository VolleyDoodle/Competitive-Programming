#include <bits/stdc++.h>
using namespace std;
vector <int> indexA, indexB;
int n, k;
int ans = 0;
void solve(){

    vector <int> count(n + 1, 0);
    for (int i = 1; i <= n; i++){
        if (indexB[i] == -1 || indexA[i] == -1) continue;
        if (indexB[i] > indexA[i]){
            count[indexA[i] + k - indexB[i]]++;
            ans = max(ans,count[indexA[i] + k - indexB[i]] );
        } else{
            count[indexA[i] - indexB[i]]++;
            ans = max(ans,count[indexA[i] - indexB[i]] );
        }
        
    }
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    cin >> n >> k;
    indexA.resize(n + 1, -1);
    indexB.resize(n + 1, -1);
    vector <int> b(k);
    for (int i = 0; i < k; i++){
        int t1;
        cin >> t1;
        indexA[t1] = i;
    }
    for (int i = 0; i < k; i++){
        int t1;
        cin >> t1;
        b[i] = t1;
        indexB[t1] = i;
    }
    solve();

    reverse(b.begin(), b.end());
    for (int i = 0; i < k; i++){
        indexB[b[i]] = i;
    }

    solve();
    for (int i = 1; i <= n; i++){
        if (indexA[i] == -1 && indexB[i] == -1){
            ans++;
        }
    }
    cout << ans;
}