#include <bits/stdc++.h>
using namespace std;
string s, t;
//conjecture:
//basically if you have abc
//then ab must be good, ac must be good and cb must be good
//could actually just generate all subsets
//then use priority_queue?
//final working solution is below
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
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    cin >> s >> t;
    vector <string> subsets;
    map <string, bool> good;
    //calculate all 2^18 possible subsets of this
    //{a, b.. r} <- 18 long?
    //first just generate all subsets
    //
    for (int i = 0; i < 17; i++){
        string ch(1, char(i + 'a'));
        good[ch] = check(ch);
        for (int x = i + 1; x < 18; x++){
            string cur = string(1, char(i + 'a')) + (char(x + 'a'));
            good[cur] = check(cur);
        }
    }
    good["r"] = check("r");
    int q;
    cin >> q;
    string ans = "";
    //cout << good["e"];
    for (int i = 0; i < q; i++){
        string tt;
        cin >> tt;
        bool goodS = true;
        for (int x = 0; x < tt.size() - 1; x++){
            for (int j = x + 1; j < tt.size(); j++){
                if (!good[string(1, tt[x]) + tt[j]]){
                    goodS = false;
                    break;
                }
            }
            if (!goodS) break;
        }
        for (int x = 0; x < tt.size(); x++){
            if (!good[string(1, tt[x])]){
                goodS = false;
                break;
            }
        }
        //basically means that all the subsets could be good
        //but still can be no
        if (!goodS){
            ans += 'N';
        } else{
            ans += 'Y';
            //ans += (check(tt) ? 'Y' : 'N');
        }
    }
    cout << ans;


}