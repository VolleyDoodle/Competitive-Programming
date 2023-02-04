
#include <vector>
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
//ifstream fin("input.in");
//ofstream //fout("output.out");
class cow {
public:
    int s; int t; int c;
};
class cond {
public:
    int a; int b; int p; int m;
};

int cbarns[101];
vector <cow> cows;

vector <int> pans;
int n, m;
void solve(vector <cond> conds, int t_ans, vector <int> barns) {
    
    for (int i = 0; i < conds.size(); i++) {
        for (int i = 0; i < barns.size(); i++) {
            //fout << barns[i] << " ";
        }
        //take away conditioner[i]
        bool work = true;
        for (int x = conds[i].a; x <= conds[i].b; x++) {
            barns[x] -= conds[i].p;
            //fout << barns[x] << " " << conds[i].p << endl;
            if (barns[x] < cbarns[x]) {
                work = false;
            }
            
        }
        //fout << "work: " << work << endl;
        //fout << "________________" << endl;
        cond temp = conds[i];
        if (work) {
            
            conds.erase(conds.begin() + i);
            solve(conds, t_ans - temp.m, barns);
            conds.push_back(temp);
            
        }
        else {
            pans.push_back(t_ans);
        }
        for (int x = temp.a; x <= temp.b; x++) {
            barns[x] += temp.p;
        }

    }

}
int main()
{
    
    
    
    vector <cond> conds;
    vector <int> barns;
    for (int i = 0; i < 101; i++) {
        barns.push_back(0);
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cow temp; cin >> temp.s >> temp.t >> temp.c;
        for (int x = temp.s; x <= temp.t; x++) {
            cbarns[x] = temp.c;
        }
        cows.push_back(temp);
    }
    int ta = 0;
    for (int i = 0; i < m; i++) {
        cond temp; cin >> temp.a >> temp.b >> temp.p >> temp.m;
        for (int i = temp.a; i <= temp.b; i++) {
            barns[i] += temp.p;
            
        }
        ta += temp.m;
        conds.push_back(temp);
    }
    
    //fout << endl;
    solve(conds, ta, barns);
    for (int i = 0; i < pans.size(); i++) {
        //fout << pans[i] << " ";
    }
    int ans = INT_MAX;
    for (int i = 0; i < pans.size(); i++) {
        ans = min(ans, pans[i]);
    }
    cout << ans;

    
    
}
