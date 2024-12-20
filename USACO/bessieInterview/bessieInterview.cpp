#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    //farmers represent the endtimes of each cow
    //pririt
    priority_queue<pair<int,int>, vector <pair <int, int>>, greater<pair <int, int>>> farmers;
    long long curTime = 0;
    for (int i = 0; i < n; i++){
        int t1;
        if (farmers.size() < k){
            farmers.push(t1 + curTime);
        }
        while (farmers.front() < curTime){
            farmers.pop();
        }
    }

}