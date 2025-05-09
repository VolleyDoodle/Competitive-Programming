#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
//i genuinily may be retarted!!!!
//so frickin retarted!!!
//super duper retarted!!!
int solve(string nstr){
    vector <vector <int>> pfs(nstr.size(), vector <int>(26, 0));
    for (int j = 0; j < nstr.size(); j++){
        if (j != 0) {
            for (int i = 0; i < 26; i++) pfs[j][i] = pfs[j - 1][i]; 
        }
        pfs[j][nstr[j] - 'a']++;
    }
    
    int insideRad = 0;
    //inside rad  = radius from middle that is palindrome
    int tempIdx = nstr.size()/2 - 1;
    while (tempIdx - insideRad + 1 >= 0 && nstr[tempIdx - insideRad] == nstr[tempIdx + insideRad + 1]){
        insideRad++;
    }

    //cout << "nstr size " << nstr.size() << "\n"; 
    //cout << "nstr: " << nstr << "\n";
    //tempIdx - inRad ... to tempIdx + inRad equals palindrome in middle of nstr
    int ans = nstr.size();
    //cout << nstr.substr(0, tempIdx + insideRad + 1) << "\n";
    //cout << "in range: " << nstr[tempIdx + insideRad] << " " << nstr[tempIdx + insideRad - 1];

    for (int i = 0; i <= tempIdx + insideRad; i++){
        //let 0.. i be the set substr, and i + 1.. nstr.size() be change str
        if (i < nstr.size()/2){
            bool impos = false;
            for (int j = 0; j < 26; j++){
                if (pfs[i][j] > (pfs[nstr.size() - 1][j] - pfs[i][j])){
                    impos = true;
                }
            }
            if (!impos) {
                ans = min(ans, (int) nstr.size() - i - 1);
                //cout << "ans: " + (int) nstr.size() - i - 1 << "\n";
                //cout << "set: " + nstr.substr(0, i + 1) << "\n";
                //cout << "change: " + nstr.substr(i + 1, nstr.size() - i - 1) << "\n";
            }
        } else{
            bool impos = false;
            //int buffer = min(i - tempIdx, insideRad) * 2;
            for (int j = 0; j < 26; j++){
                //int val = (insideRad == 0 ? 0 : pfs[min(i, tempIdx + insideRad)][j] - pfs[tempIdx - insideRad][j]);
                int val1 = 0;
                int val2 = pfs[nstr.size() - 1][j] - pfs[tempIdx + insideRad][j];
                if (insideRad == 0){
                    val1 = 0;
                } else{
                    val1 = pfs[tempIdx - insideRad][j];
                }
                if (val1 < val2){
                    impos = true;
                }
            }
            if (!impos){
                ans = min(ans, (int) nstr.size() - i - 1);
                //cout << "ans: " +  (int) nstr.size() - i - 1 << "\n";
                //cout << "WHAT \n";
                //cout << "buffer: " << buffer << "\n";
                //cout << "set: " << nstr.substr(0, i + 1) << "\n";
                //cout << "change: " << nstr.substr(i + 1, nstr.size() - i - 1) << "\n";
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        string tots;
        cin >> tots;
        int idx = 0;
        while (idx < tots.size()/2 && tots[idx] == tots[tots.size() - idx - 1]){
            idx++;
        }        
        if (idx == tots.size()/2){
            cout << 0 << "\n";
            continue;
        }

        string nstr = tots.substr(idx, tots.size() - 2 * idx);
        
        int ans = nstr.size();
        ans = min(ans, solve(nstr));
        reverse(nstr.begin(), nstr.end());
        ans = min(ans, solve(nstr));
        cout << ans << "\n";
        
    }
}