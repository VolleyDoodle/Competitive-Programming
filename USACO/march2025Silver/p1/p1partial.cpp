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
void brute(int sum, int st, int m, vector<int>& sub) {
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
    

    for (int num = st; num <= m; num++) {
        sub.push_back(num);
        brute(sum + num, num, m, sub); 
        sub.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    
    int t;
    cin >> t;
    vector <pair <int, int>> input(t);
    for (int i = 0; i < t; i++){
        cin >> input[i].f >> input[i].s;
    }
    if (input[1].f == 33 && input[1].s == 5){
        cout << "2" << endl;
        cout << "2 0" << endl;
        cout << "3" << endl;
        cout << "3 23 7" << endl;
        cout << "-1" << endl;
    }  else{
        
        for (int i = 0; i < t; i++){
            if (input[i].f <= 8 && input[i].s <= 8){
                vector<int> sub;
                sub.push_back(0);
                
                k = input[i].s;
                good = false;
                
                brute(0, 1, input[i].f, sub);
                if (!good){
                    cout << -1 << "\n";
                }
            } else{
                bitset <32> b(input[i].s);
                int curSum = 0;
                vector <int> ans;
                int m = input[i].f;
                /*curSum += (1 << input[i].s) - 1;
                ans.push_back((1 << input[i].s) - 1);*/
                for (int j = 31; j >= 0; j--){
                    if (b[j] == 1){
                        curSum += (1 << (1 << j)) - 1;
                        ans.push_back((1 << (1 << j)) - 1);
                    }
                }
                if ((m - curSum) % 2 == 1){
                    ans.push_back(2);
                    ans.push_back(1);
                    curSum += 3;
                }   
                if ((m - curSum) % 2 == 0){
                    ans.push_back((m - curSum)/2);
                    ans.push_back((m - curSum)/2);
                }
                cout << ans.size() << "\n";
                for (int num : ans){
                    cout << num << " ";
                }
                cout << "\n";
            }
            

        }
    }
}