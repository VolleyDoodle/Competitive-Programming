#include <bits/stdc++.h>
using namespace std;
string s, t;
//conjecture:
//basically if you have abc
//then ab must be good, ac must be good and cb must be good
//could actually just generate all subsets
//then use priority_queue?

bool check(string sub){
    string tempS = "", tempT = "";
    for (int i = 0; i < s.size(); i++){
        if (s[i] == sub[0] || s[i] == sub[1]){
            tempS+=s[i];
        }
    }
    for (int i = 0; i < t.size(); i++){
        if (t[i] == sub[0] || t[i] == sub[1]){
            tempT+=t[i];
        }
    }

    return tempS == tempT;
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    cin >> s >> t;
    vector <string> subsets;
    map <string, bool> good;
    //calculate all 2^18 possible subsets of this
    //{a, b.. r} <- 18 long?
    //first just generate all subsets
    for (int i = 0; i < (1 << 18); i++){
        string temp = "";
        for (int j = 0; j < 18;j++){
            if (i & (1 << j)){
                temp += char(j + 'a');
            }
        }
        //if (temp.size() <= 1) continue;
        subsets.push_back(temp);
    }
    sort(subsets.begin(), subsets.end(), []
        (const auto& a, const auto& b){
            return a.size() < b.size();
        }
    );
    //cout << subsets.size();
    for (string sub : subsets){
        if (sub.size() == 2){
            good[sub] = check(sub);
        }
        else{
            //if size three, the just iterating through all subsets 2
            //if size 4, then iterating through all susbets 3.. and so on
            bool goodS = true;  
            /*string curS = "";
            vector <string> subM(sub.size(), "");
            for (int i = 0; i < sub.size(); i++){
                subM[i] += curS + sub[i];
                curS += sub[i];
            }
            curS = "";
            for (int i = sub.size() - 1; i >= 0; i--){
                subM[i] += curS;
                curS += sub[i];
            }*/
            for (int i = 0; i < sub.size(); i++){
                //just take away this index[i]
                //string temp = subM[i];
                string temp = sub;
                temp.erase(i, 1);
                if (!good[temp]){
                    goodS = false;
                    break;
                }
            }
            good[sub] = goodS;
        }
    }
    int q;
    cin >> q;
    string ans = "";
    for (int i = 0; i < q; i++){
        string tt;
        cin >> tt;
        ans+= (good[tt] ? "Y" : "N");
    }
    cout << ans;


}