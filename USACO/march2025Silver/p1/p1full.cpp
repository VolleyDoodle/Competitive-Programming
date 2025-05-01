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
    
    int t;
    cin >> t;
    while (t--){
        int m, k;
        cin >> m >> k;
        bitset <32> b(k);
        int curSum = 0;
        vector <int> ans;
        ;
        /*curSum += (1 << input[i].s) - 1;
        ans.push_back((1 << input[i].s) - 1);*/
        for (int j = 31; j >= 0; j--){
            if (b[j] == 1){
                curSum += (1 << (1 << j)) - 1;
                ans.push_back((1 << (1 << j)) - 1);
            }
        }
        if (curSum > m){

            cout << -1 << "\n";
            continue;
        }
        if ((m - curSum) == 1){
            if (1 & k){
                ans.pop_back();
                ans.push_back(2);
                curSum++;
            } else{
                cout << -1 << "\n";
                continue;
            }
            
        }   
        if ((m - curSum)%2 == 1){
            ans.push_back(2);
            ans.push_back(1);
            curSum += 3;
        }   
        if ((m - curSum) % 2 == 0 && (m - curSum != 0)){
            ans.push_back((m - curSum)/2);
            ans.push_back((m - curSum)/2);
        }
        if (ans.size() > 100){
            cout << -1 << "\n";
            continue;
        }
        cout << ans.size() << "\n";
        for (int num : ans){
            cout << num << " ";
        }
        cout << "\n";
    }
}