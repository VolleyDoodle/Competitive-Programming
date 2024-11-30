#include <bits/stdc++.h>
using namespace std;
//basically carrara's solution
char ans;
string s;
long long total, n, curIndex;
void solve(){
    if (curIndex <= s.size()){
        return;
    }    
    if (curIndex <= total/2){
        total/=2;
        solve();
    } 
    else{
        curIndex = (curIndex)%(total/2 + 1);
        //dumb way
        /*if (curIndex == total/2 + 1){
            curIndex = total/2;
        } else{
            curIndex = curIndex - (total/2 + 1);
        }*/
        total/=2;
        solve();
    } 
}

int main(){
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    cin >> s >> n;
    //s = s[s.size() - 1] + s;
    curIndex = n;
    total = s.size();
    while (total < n){
        total*=2;
    }
    //curIndex--;
    solve();
    cout << s[curIndex - 1];
    
}