#include <bits/stdc++.h>
#define ll long long
#define f first
using namespace std;
int n;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
vector <int> v;
int log2(int num){
    int cnt = 0;
    while (num > 1){
        num/=2; 
        cnt++;
    }
    return cnt;
}
void solve(vector <string> a){
    //first need to make a spa table for this
    //ts geniunely pmo but its aight
    int base = log2(a.size());
    vector <vector <pair <string, int>>> spa(base + 1);
    for (int p = 0; p <= base; p++){
        spa[p].resize(a.size() - (1 << p) + 1);
        for (int i = 0; i <= a.size() - (1 << p); i++){
            if (p == 0) spa[p][i] = {a[i], i};
            else {
                if (spa[p - 1][i].f <= spa[p - 1][i + (1 << (p - 1))].f){
                    spa[p][i] = spa[p - 1][i];
                } else{
                    spa[p][i] = spa[p - 1][i + (1 << (p - 1))];
                }
            }
        }
    }
    //cout << "h";

    //for given l-mer
    //now need to calc all k-mer with this
    //l = a[0].size()
    for (int k = a[0].size(); k <= n; k++){
        //k = kmer size
        set <int> pos;
        
        int length = k - a[0].size() + 1;
        int idx = log2(length);
        for (int i = 0; i <= n - k; i++){
            if (length == 0) pos.insert(i);
            else if (spa[idx][i].f <= spa[idx][(i + length) - (1 << idx)].f){
                pos.insert(spa[idx][i].second);
            } else{
                pos.insert(spa[idx][(i + length) - (1 << idx)].second);
            }
        }
        v[pos.size()]++;
    }
    //cout << "h";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");

    cin >> n;
    string s;
    cin >> s;
    vector <vector <string>> arr(n);
    v.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < n - i + 1; j++){
            arr[i - 1].push_back(s.substr(j, i));
        }
    }
    for (int i = 0; i < n; i++){
        solve(arr[i]);
    }
    for (int i = 1; i <= n; i++){
        cout << v[i] << "\n";
    }
    //cout << "h";
}