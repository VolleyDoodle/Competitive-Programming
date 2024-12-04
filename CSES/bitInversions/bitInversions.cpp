#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string bit;
    cin >> bit;

    set <int> zeros, ones;
    multiset <int> lens;
    //could have used vector <set <int>> instead of using all these if/else statements
    //definitly could use 2d vector of size 2 with sets instead of repetitve code and if else
    zeros.insert(-1); 
    ones.insert(-1); 
    for (int i = 0; i < bit.size(); i++){
        //if (bit[i] == '0') zeros.insert(i);
        //else ones.insert(i);
        if (bit[i] == '0'){
            int endVal = *--zeros.end();
            lens.insert(i - endVal);
            zeros.insert(i);
        } else{
            int endVal = *--ones.end();
            lens.insert(i - endVal);
            ones.insert(i);
        }
    }
    lens.insert(bit.size() - *--zeros.end());
    lens.insert(bit.size() - *--ones.end());
    ones.insert(bit.size());   
    zeros.insert(bit.size());
    
    
    int m;
    cin >> m;
    while (m--){
        int x;
        cin >> x;
        x--;
        if (bit[x] == '0'){
            //changing 0 to 1
            bit[x] = '1';
            auto it = zeros.find(x);
            int nxt = *next(it);
            int prv = *prev(it);
            
            lens.erase(lens.find(nxt - *it));
            lens.erase(lens.find(*it - prv));
            lens.insert(nxt - prv);
            zeros.erase(it);

            ones.insert(x);
            it = ones.find(x);
            nxt = *next(it);
            prv = *prev(it);
            lens.erase(lens.find(nxt - prv));
            lens.insert(nxt - *it);
            lens.insert(*it - prv);
            //both of them update ugghhghghg

        } else {
            bit[x] = '0';
            auto it = ones.find(x);
            int nxt = *next(it);
            int prv = *prev(it);
            
            lens.erase(lens.find(nxt - *it));
            lens.erase(lens.find(*it - prv));
            lens.insert(nxt - prv);
            ones.erase(it);

            zeros.insert(x);
            it = zeros.find(x);
            nxt = *next(it);
            prv = *prev(it);
            lens.erase(lens.find(nxt - prv));
            lens.insert(nxt - *it);
            lens.insert(*it - prv);
        }
        cout << (*--lens.end()) - 1 << " ";
         
    }

}