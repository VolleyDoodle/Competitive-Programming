//only designed for subtask #1
#include <bits/stdc++.h>
using namespace std;
void fBigger(vector<int>& f, vector<int>& s, int& thirdTube);
void sBigger(vector<int>& f, vector<int>& s, int& thirdTube);
void fBigger(vector<int>& f, vector<int>& s, int& thirdTube){
    bool ran = false;
    if (s[s.size() - 1] == f[f.size() - 1]){
        cout << "1 2" << "\n";
        f.pop_back();
        ran = true;
    } else if (f[f.size() - 1] == thirdTube || thirdTube == -1){
        thirdTube = f[f.size() - 1];
        cout << "1 3" << "\n";
        f.pop_back();
        ran = true;
    }
    if (!ran){
        sBigger(f, s, thirdTube);
    }
}
void sBigger(vector <int>& f, vector <int>& s, int& thirdTube){
    bool ran = false;
    if (s[s.size() - 1] == f[f.size() - 1]){
        cout << "2 1" << "\n";
        s.pop_back();
        ran = true;
    } else if (s[s.size() - 1] == thirdTube || thirdTube == -1){
        thirdTube = s[s.size() - 1];
        cout << "2 3" << "\n";
        s.pop_back();
        ran = true;
    }
    if (!ran){
        fBigger(f, s, thirdTube);
    }
}
void solve(){
    int n, p;
    cin >> n >> p;
    vector <int> f, s;
    for (int i = 0; i < n; i++){
        char t2;
        cin >> t2;
        int t1 = t2 - '0';
        if (f.size() == 0){
            f.push_back(t1);
            continue;
        }
        if (t1 != f[f.size() - 1]) f.push_back(t1);
    }
    for (int i = 0; i < n; i++){
        char t2;
        cin >> t2;
        int t1 = t2 - '0';
        if (s.size() == 0){
            s.push_back(t1);
            continue;
        }
        if (t1 != s[s.size() - 1]) s.push_back(t1);
    }
    if (f.size() == 2 && s.size() == 1){
        cout << 1; 
    } else if (f.size() == 1 && s.size() == 2){
        cout << 1;
    } else if (f.size() + s.size() == 2){
        cout << 0; 
    }
    else if (f[0] != s[0]){
        cout << f.size() + s.size() - 1;
    } else{
        cout << f.size() + s.size();
    }
    if (p == 1) return;
    cout << "\n";
    //implmenting this seems hard no cap
    if (f[0] != s[0]){
        //third tube just represents which 1/2 its holding currently
        //basically incorrect
        //int thirdTube = f[f.size() - 1];
        int thirdTube = -1;
        while (!(f.size() == 1 && s.size() == 1)){
            if (f.size() >= s.size()){
                fBigger(f, s, thirdTube);
            } if (f.size() < s.size()){
                sBigger(f, s, thirdTube);
            }
        }
        if (thirdTube == f[0]){
            cout << "3 1";
        } else if (thirdTube == s[0]){
            cout << "3 2";
        }
    } else{
        //this part probably works
        int thirdTube = (f[0] == 1 ? 2 : 1);
        while (!(f.size() == 1 && s.size() == 1)){
            for (int i = 1; i <= 2; i++){
                if (i == 1){
                    // use f
                    while (f.size() > 1){
                        bool pos = false;
                        if (f[f.size() - 1] == s[s.size() - 1]){
                            cout << "1 2";
                            f.pop_back();
                            pos = true;
                        } else if (f[f.size() - 1] == thirdTube){
                            cout << "1 3";
                            f.pop_back();
                            pos = true;
                        }
                        if (!pos) break;
                        cout << "\n";
                    }
                } if (i == 2){
                    while (s.size() > 1){
                        bool pos = false;
                        if (f[f.size() - 1] == s[s.size() - 1]){
                            cout << "2 1";
                            s.pop_back();
                            pos = true;
                        } else if (s[s.size() - 1] == thirdTube){
                            cout << "2 3";
                            s.pop_back();
                            pos = true;
                        }
                        if (!pos) break;
                        cout << "\n";
                    }
                }
            }

        }
        cout << "2 1" << "\n";
        cout << "3 2";
    }
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    
    while (t--){
        solve();
        cout << "\n";
    }
}