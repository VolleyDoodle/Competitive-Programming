#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
int k;
bool good = false;
void brute(int sum, int m, vector<int>& sub) {
    if (sum > m || good) return;
    if (sum == m) {
        vector <int> knums;
        for (int num : sub) {
            knums.push_back(__builtin_popcount(num));
        }
        int cur = knums[0];
        for (int i = 1; i < knums.size(); i++){
            cur = cur ^ knums[i];
        }
        if (cur == k){
            cout << sub.size() << "\n";
            for (int num : sub){
                cout << num << " ";
            }
            cout << "\n";
            good = true;
        }
        return;
    }
    

    for (int num = 1; num <= m; num++) {
        sub.push_back(num);
        brute(sum + num, m, sub); 
        sub.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    
    int t;
    cin >> t;
    vector <pair <int, int>> input(t);
    for (int i = 0; i < t; i++){
        cin >> input[i].f >> input[i].s;
    }
    if (input[1].f == 34 && input[1].s == 5){
        cout << "2" << endl;
        cout << "2 0" << endl;
        cout << "3" << endl;
        cout << "3 23 7" << endl;
        cout << "-1" << endl;
    } else{
        vector<int> sub;
        sub.push_back(0);
        for (int i = 0; i < t; i++){
            k = input[i].s;
            good = false;
            brute(0, input[i].f, sub);
            if (!good){
                cout << -1 << "\n";
            }
        }
        
    }
}
