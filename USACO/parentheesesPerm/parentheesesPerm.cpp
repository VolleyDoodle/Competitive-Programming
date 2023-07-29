#include <bits/stdc++.h>
using namespace std;
int n, v = 0;
void solve(string curPerm, int openAmt, int closedAmt){
    v++;
    //two choices 
    //-open parentheeses or closed
    cout << "OpenAmt: " << openAmt << "| ClosedAmt" << closedAmt << "\n";
    cout << curPerm << "\n";
    if (openAmt == n && closedAmt == n){
        //cout << curPerm << "\n";
        return;
    }
    if (openAmt > closedAmt){
        solve(curPerm + ")", openAmt, closedAmt + 1);
    }
    if (openAmt != n){
        solve(curPerm + "(", openAmt + 1, closedAmt);
    }
}

int main(){
    cin >> n;
    solve("", 0, 0);
    cout << v;
}