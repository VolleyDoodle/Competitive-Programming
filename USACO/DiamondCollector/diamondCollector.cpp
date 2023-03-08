#include <bits/stdc++.h>
//correct ans = 4541
//first is 2342
//second is 1740
using namespace std;
vector <int> diamonds;
int n, k,  finalAns = 0;
void solve(){
    int startIndex = -1, endIndex = -1, curCase = -1;
    for (int i = 0; i < n; i++){
        auto lastElement = upper_bound(diamonds.begin(), diamonds.end(), diamonds[i] + k );
        if ((lastElement - diamonds.begin()) - i > curCase){
            startIndex = i;
            endIndex = lastElement - diamonds.begin();
            curCase = (lastElement - diamonds.begin()) - i;
        }
    }
    
    diamonds.erase(diamonds.begin() + startIndex, diamonds.begin() + endIndex);
    finalAns+=curCase;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    cin >> n >> k;
    diamonds.resize(n); 
    for (int i = 0; i < n; i++){ cin >> diamonds[i];}
    sort(diamonds.begin(), diamonds.end());
    solve();
    solve();
    cout << finalAns;
    

    

}