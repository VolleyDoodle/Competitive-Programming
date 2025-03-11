#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
//i may be special?
//b/c for some eason i always try the hardest problems first
//and then jusrt get hardstuck for the whole contest

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void solve(){
    int n;
    cin >> n;
    //god bless alphastar for their instructors and solutions
    vector <int> a(n);
    vector <pair <int, int>> canSave;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mx1 = 0, mx2 = 0;
    for (int i = n - 1; i >= 0; i--){
        if (a[i] >= mx1){
            mx2 = mx1;
            mx1 = a[i];
        } else if (a[i] >= mx2){
            mx2 = a[i];
            canSave.push_back({a[i], i});
        }
    }
    //sort(canSave.begin(), canSave.end());
    //cout << "h";
    if (!canSave.empty()){
        for (int i = canSave[canSave.size() - 1].s + 1; i < n; i++){
            if (a[i] > canSave[canSave.size() - 1].f){
                int temp = a[i];
                a.erase(a.begin() + i);
                a.insert(a.begin() + canSave[canSave.size() - 1].s, temp);
                break;
            }
        }
    }
    stack <int> s;
    for (int i = 0; i < n; i++){
        while (!s.empty() && a[i] > s.top()){
            s.pop();
        }
        s.push(a[i]);
    }
    vector <int> ans;
    while (!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    for (int i = ans.size() - 1; i >= 1; i--){
        cout << ans[i] << " ";
    }
    cout << ans[0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
}