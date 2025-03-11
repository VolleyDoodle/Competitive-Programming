#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int n;
    cin >> n;
    vector <int> childNum(n + 1, 0);
    vector <int> height(n + 1, 0);
    vector <int> p(n);
    for (int i = 1; i <= n; i++){
        int pi;
        cin >> pi;
        p[i - 1] = pi;
        childNum[pi]++;
        height[i] = height[pi] + 1;
    }
    int m = 0;
    for (int i = 0; i < n + 1; i++){
        if (childNum[i] == 0) m++;
    }
    for (int i = 0; i < m; i++){
        //now what...
        int cnt = 0;
        int cur;
        cin >> cur;
        while (true){
            //ok ese
            //wtf is ts, i cant think, cant move, what am i doing
            if (cur == 0){
                cout << 0;
                break;
            }
            if (childNum[p[cur - 1]] == 1){
                //childNum[p[cur - 1]] = 0;
                cur = p[cur - 1];
            } else{
                //> 1
                //so should stop right around here!
                //if its equal to zero then idk i did smthn wrong
                cout << height[cur];
                childNum[p[cur - 1]]--;
                break;
            }
        }
        cout << "\n";
    }

}