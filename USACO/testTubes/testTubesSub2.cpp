//only designed for subtask #1
#include <bits/stdc++.h>
using namespace std;
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
    
    int ans = 0;
    //implmenting this seems hard no cap
    if (f[0] != s[0]){
        //third tube just represents which 1/2 its holding currently
        //basically correct
        int thirdTube = -1;
        while(f.size() > 1){
            
            if (s[s.size() - 1] == f[f.size() - 1]){
                cout << "1 2";
                f.pop_back();
            } else{
                thirdTube = f[f.size() - 1];
                cout << "1 3";
                f.pop_back();
            }
            
            cout << "\n";
        }
        while (s.size() > 1){
            if (s[s.size() - 1] == f[f.size() - 1]){
                cout << "2 1";
                s.pop_back();
            } else{
                thirdTube = s[s.size() - 1];
                cout << "2 3";
                s.pop_back();
            }
            cout << "\n";
        }
        if (s[0] == thirdTube){
            cout << "3 2" << "\n";
        } else if (f[0] == thirdTube){
            cout << "3 1" << "\n";
        }

    } else{
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
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    
    while (t--){
        solve();
        cout << "\n";
    }
}