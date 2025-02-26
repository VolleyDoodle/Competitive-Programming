#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    vector <pair <int, int>> sortA(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sortA[i].f = a[i];
        sortA[i].s = i;
    }
    sort(sortA.begin(), sortA.end());
    /*sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.f != b.f){
            return a.f > b.f;
        }
        return a.s > b.s;
    });*/

    reverse(sortA.begin(), sortA.end());
    vector <int> ans;
    int movedIdx = -1;
    for (int i = 0; i < n; i++){
        if (a[i] != sortA[i].f){
            //do operation
            movedIdx = sortA[i].s;
            ans.push_back(sortA[i].f);
            int start = i + 1;
            for (int x = i; x < n; x++){
                if (start == n) break;
                if (a[x] != sortA[start].f){
                    continue;
                } else{
                    ans.push_back(a[x]);
                    start++;
                }
            }
            break;
        } else{
            ans.push_back(a[i]);
        }
    }
    for (int i = 0; i < ans.size() - 1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size() - 1];


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}