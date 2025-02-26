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
    vector <int> a(n), na(n);
    vector <pair <int, int>> sortA(n);
    for (int i = 0; i < n; i++){
        cin >> na[i];
        
    }
    //sort(sortA.begin(), sortA.end());
    vector <int> prefix1(n, 0), suffix1(n, 0);
    prefix1[0] = na[0];
    for (int i = 1; i < n; i++){
        prefix1[i] = max(prefix1[i - 1], na[i]);
    }
    suffix1[n - 1] = na[n - 1];
    for (int i = n - 2; i >= 0; i--){
        suffix1[i] = max(suffix1[i + 1], na[i]);
    }
    int newIndex = 0;
    for (int i = 1; i < n - 1; i++){
        if (prefix1[i - 1] < suffix1[i + 1] && na[i] > prefix1[i - 1]){
            //can just delete all of prefix1
            newIndex = i;
        }
    }
    for (int i = newIndex; i < n; i++){
        a[i - newIndex] = na[i];
        sortA[i - newIndex].f = a[i - newIndex];
        sortA[i - newIndex].s = i - newIndex;
    }
    n-=newIndex;
    sort(sortA.begin(), sortA.end(), [](const pair<int, int>& a1, const pair<int, int>& b1) {
        if (a1.f != b1.f){
            return a1.f > b1.f;
        }
        return a1.s < b1.s;
    });
    int movedIdx = -1;
    //reverse(sortA.begin(), sortA.end());
    for (int i = 0; i < n; i++){
        if (a[i] != sortA[i].f){
            int lastE = -1;
            for (int x = i; x < n; x++){
                if (a[x] == sortA[i].f){
                    lastE = x;
                }
            }
            a.erase(a.begin() + lastE);
            a.insert(a.begin() + i, sortA[i].f);
            break;
        }
    }
    //create suffix
    vector <int> suffix(n + 1, 0);
    for (int i = n - 1; i >= 0; i--){
        suffix[i] = max(suffix[i + 1], a[i]);
    }
    vector <int> ans;
    //already moved
    for (int i = 0; i < n; i++){
        if (a[i] != sortA[i].f){
            //see
            int aIdx = i;
            for (int x = i; x < n; x++){
                if (aIdx == n) break;
                if (a[aIdx] == sortA[x].f){
                    ans.push_back(a[aIdx]);
                    aIdx++;
                }
                else if (suffix[aIdx] < sortA[x].f){
                    continue;
                } else{
                    aIdx++;
                    x--;
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
        if (t == 0) continue;
        cout << "\n";
    }
}