
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
int main()
{
    int n,t, temp;
    int mn;
    int p_ans = 0, ans =0;
    int check = 0;
    cin >> n;
    for (int d = 0; d < n; d++) {
        cin >> t; vector<int> v(t); vector <int> vc(t);
        //cout << t << endl;
        for (int x = 0; x < t; x++) {
            //cout << "WORKING" << endl;
            cin >> temp; 
            v.at(x) = temp;
            vc.at(x) = temp;
            //cout << temp << endl;
            //cout << v[x] << endl;
        }
        //find min
        mn = v[0];
        for (int y = 0; y < t; y++) {if (v[y] < mn) { mn = v[y]; }}
        //cout << mn;
        //Logic LOL
        for (int z = 0; z <= mn; z++) {
            for (int i = 0; i < t - 1; i++) {
                if (v[i] > z) {
                    temp = min(v[i], v[i + 1]) - z;
                    v[i] -= temp; v[i + 1] -= temp;
                    p_ans += temp * 2;
                }
            }
            //check for success
            for (int b = 0; b < t; b++) { 
                if (v[0] == v[b]){ 
                    check++; 
                } 
            }
            //reset data since no fn :(
            if (check == t) {
                if (ans != 0) { ans = min(ans, p_ans); }
                else { ans = p_ans; }
            }
            check = 0;
            p_ans = 0;
            for (int j = 0; j < t; j++) { v.at(j) = vc[j]; }
        }
        
        //cout << "ANS: " << ans << endl;
        if (ans == 0) { cout << "-1" << endl; }
        else { cout << ans << endl; }
        ans = 0, p_ans = 0;
        
    }
}
