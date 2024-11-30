#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> n;
    vector <pair <int, int>> cords(n);
    map <pair <int, int>, long long> vertsum, horizsum;
    map <int, vector <int>> yx, xy;
    for (int i = 0; i < n; i++){
        cin >> cords[i].first >> cords[i].second;
        cords[i].first+=10000; cords[i].second+=10000;
        yx[cords[i].second].push_back(cords[i].first);
        xy[cords[i].first].push_back(cords[i].second);
    }

    for (auto& v : yx){sort(v.second.begin(), v.second.end()); } //same y-cord (use for horizsum)
    for (auto& v : xy){sort(v.second.begin(), v.second.end()); } //same x-cord (use for vertsum)
    //sort by x cordinates then calculate vertical sum (all points w/ same x-cord)
    for (auto& v : yx){
        for (int i = 0; i < v.second.size(); i++){
            horizsum[{v.second[0], v.first}]+=v.second[i] - v.second[0];
        }
        for (int i = 1; i < v.second.size(); i++){
            horizsum[{v.second[i], v.first}] = horizsum[{v.second[i - 1], v.first}] - (v.second.size() - 2 * i) * (v.second[i] - v.second[i - 1]);
        }
    }
    for (auto& v : xy){
        for (int i = 0; i < v.second.size(); i++){
            vertsum[{v.first, v.second[0]}]+=v.second[i] - v.second[0];
        }
        for (int i = 1; i < v.second.size(); i++){
            vertsum[{v.first, v.second[i]}] = vertsum[{v.first, v.second[i - 1]}] - (v.second.size() - 2 * i) * (v.second[i] - v.second[i - 1]);

        }
    }
    long long ans = 0;
    for (pair <int, int> cord : cords){
        ans+=vertsum[cord] * horizsum[cord];
    }
    ans%=mod;
    cout << ans;

}