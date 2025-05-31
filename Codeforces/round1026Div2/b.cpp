#include <bits/stdc++.h>
#define ll long long
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        //check if not palindrome
        bool pal = true;
        for (int i = 0; i < s.size()/2; i++){
            if (s[i] == ')'){
                pal = false;
            }
            /*if (s[i] == '(' && s[s.size() - i - 1] == '('){
                pal = false;
            }*/
        }
        if (pal) {
            cout << "NO" << "\n";
        } else{
            cout << "YES" << "\n";
        }
    }
}