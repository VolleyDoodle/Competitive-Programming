#include <bits/stdc++.h>
using namespace std;
int n;
vector <pair <int, int>> friends; //first -> location, second -> max speed
//basically just binary searching possible time
//seeing if possible and just narrowing down to 10^-6 precision
bool check(double maxTime){
    
}
int main(){
    cin >> n;
    friends.resize(n);
    for (int i = 0; i < n; i++){
        cin >> friends[i].first;
    }
    for (int i = 0; i < n; i++){
        cin >> friends[i].second;
    }
    double ans = 1e9;
    double lo = 1, hi = 1e9;
    while (hi - lo >= 1e-6){
        double mid = lo + (hi - lo)/2;
        if (check(mid)){
            ans = mid;
            mid = hi - 1e-6;
        } else{
            lo = mid + 1e-6;
        }
    }
}