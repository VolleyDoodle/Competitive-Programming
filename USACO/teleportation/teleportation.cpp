#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;
vector <pair <int, int>> events;
void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
void make_event(int a, int b){
    if (abs(a) >= abs(a - b)) return;
    events.push_back({b, -2});
    if (a <= b && a <= 0){
        events.push_back({0, 1});
        events.push_back({2 * b, 1});
    }
    else if (a <= b && a  >= 0){
        int dist = abs(a - b) - abs(a);
        events.push_back({b - dist, 1});
        events.push_back({b + dist, 1});
    } else if (a >= b && a <= 0){
        int dist = abs(a - b) - abs(a);
        events.push_back({b - dist, 1});
        events.push_back({b + dist, 1});
    } else if (a >= b && a >= 0){
        events.push_back({0, 1});
        events.push_back({2 * b, 1});
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("teleport");
    int n;
    cin >> n;
    vector <pair <int, int>> intv(n);
    ll total = 0, totMax = 0, curSave = 0;
    for (int i = 0; i < n; i++){
        cin >> intv[i].f >> intv[i].s;
        total += abs(intv[i].f - intv[i].s);
        make_event(intv[i].f, intv[i].s);
    }
    sort(events.begin(), events.end());
    ll curSlope = 0;
    for (int i = 0; i < events.size() - 1; i++){
        //process then calculate
        curSlope+=events[i].s;
        curSave += curSlope * (events[i + 1].f - events[i].f);
        totMax = max(totMax, curSave);
    }
    cout << total - totMax;
}