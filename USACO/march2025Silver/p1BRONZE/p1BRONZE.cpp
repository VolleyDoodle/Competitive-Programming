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
    //setIO("txt");
    int n, m;
    cin >> n >> m;
    //winnersOf[i] holds the symbols that win against i
    vector <vector <int>> winnersOf(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            char c;
            cin >> c;
            if (c == 'W'){
                winnersOf[j].push_back(i);
            } 
            if (c == 'L'){
                winnersOf[i].push_back(j);
            }
        }
    }

    while (m--){
        //finding union of two sets, aka symbols that beat both of bessie
        ll ans = 0;
        int s1, s2;
        cin >> s1 >> s2;
        set <int> s1Win;
        int bothWin = 0;
        for (int& num : winnersOf[s1]){
            s1Win.insert(num);
        }
        for (int& num : winnersOf[s2]){
            if (s1Win.count(num)) bothWin++;
        }
        //could also use for loop with bothWin as range
        ans += ((ll) bothWin * bothWin) + ((ll)bothWin * 2 * (n - bothWin));
        cout << ans << "\n";
    }
}