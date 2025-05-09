#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int n, q;
        cin >> n >> q;
        vector <int> weights(n), xorsf(n + 1, 0);
        vector <vector <int>> msbs(32);
        for (int i = 0; i < 32; i++){
            msbs[i].push_back(-1);
        }
        for (int i = 0; i < n; i++){
            cin >> weights[i];
            msbs[32 - __builtin_clz(weights[i])].push_back(i);
        }
        for (int i = n - 1; i >= 0; i--){
            xorsf[i] = weights[i] ^ xorsf[i + 1];
        }
        while (q--){
            int x, ans = 0;
            int curIndex = n;
            cin >> x;
            int curMsb = 32 - __builtin_clz(x);
            while (true){
                if (curIndex < 0) break;
                auto it = lower_bound(msbs[curMsb].begin(), msbs[curMsb].end(), curIndex);
                //it points to index that is GREATER than curIndex
                //subtract by 1 to find nxt Msb index which is before curIndex
                /*if (it == msbs[curMsb].begin()){
                    cout <<"\n it ran \n";
                    cout << "it: " << *it << "\n";
                }*/
                it--;
                int curMaxIndex = *it;
                for (int i = curMsb + 1; i < 32; i++){
                    auto it1 = lower_bound(msbs[i].begin(), msbs[i].end(), curIndex);
                    /*if (it1 == msbs[i].begin()){
                        cout << "it1 rasn" << "\n";
                    }*/
                    it1--;
                    if (*it1 > *it){
                        curMaxIndex = max(curMaxIndex, *it1);
                    }
                }
                if (curMaxIndex != *it || *it == -1){
                    ans += (curIndex - curMaxIndex - 1);
                    break;
                }
                else{
                    //it--;
                    int temp = x ^ xorsf[*it + 1];
                    if (temp >= weights[*it]){
                        //woohoo
                        curMsb = 32 - __builtin_clz(temp ^ weights[*it]);
                        ans += curIndex - *it;
                        curIndex = *it;    
                    } else{
                        ans += (curIndex - *it - 1);
                        break;
                    }
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}   