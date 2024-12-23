#include <bits/stdc++.h>
using namespace std;
vector <long long> ans;
string s;
int n;
//literally just brute force
//did it cause good way to debug final sol
// 4/15 test cases
void solve(int& k, int& l){
    vector <string> kmers;
    for (int i = 0; i < n - k + 1; i++){
        string curKmer = "";
        for (int x = i; x < i + k; x++){
            curKmer+=s[x];
        }
        kmers.push_back(curKmer);
    }
    set <int> pos;
    for (int x = 0; x < kmers.size(); x++){
        string kmer = kmers[x];
        string minLstring = kmer.substr(0, l);
        int minPos = 0;
        for (int i = 0; i < kmer.size() - l + 1; i++){
            string lString = "";
            int curPos = i;
            for (int x = i; x < i + l; x++){
                lString+=kmer[x];
            }    
            if (lString < minLstring){
                minLstring = lString;
                minPos = curPos;
            }
        }
        pos.insert(minPos + x);
    }
    ans[pos.size()]++;
        

}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    ans.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= i; x++){
            solve(i, x);
        }
    }
    for (int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
}