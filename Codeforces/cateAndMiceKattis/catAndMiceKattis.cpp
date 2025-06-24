#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    //lets see, again an ordering problem where we need to build off past states
    
    for (int s = 0; s < (1 << n); s++){
            
    }
}