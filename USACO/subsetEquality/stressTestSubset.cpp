#include <bits/stdc++.h>
using namespace std;
string s, t;
//conjecture:
//basically if you have abc
//then ab must be good, ac must be good and cb must be good
//could actually just generate all subsets
//then use priority_queue? NYNNYN 

bool check(string sub){
    string tempS = "", tempT = "";
    for (int i = 0; i < s.size(); i++){
        if (find(sub.begin(), sub.end(), s[i]) != sub.end()){
            tempS += s[i];
        }
    }
    for (int i = 0; i < t.size(); i++){
        if (find(sub.begin(), sub.end(), t[i]) != sub.end()){
            tempT += t[i];
        }
    }

    return tempS == tempT;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    cin >> s >> t;
    //vector <string> subsets;
    //map <string, bool> good;
    //calculate all 2^18 possible subsets of this
    //{a, b.. r} <- 18 long?
    //first just generate all subsets
    
    int q;
    cin >> q;
    string ans = "";
    for (int i = 0; i < q; i++){
        string tt;
        cin >> tt;
        ans += (check(tt) ? 'Y' : 'N');
    }
    cout << ans;


}