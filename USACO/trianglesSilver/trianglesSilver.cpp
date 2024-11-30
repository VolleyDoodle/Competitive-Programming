#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    long long n;
    
    cin >> n;
    vector <pair <long long, long long>> cords(n);
    map <long long, vector <long long>> yx, xy;
    map <long long, long long> xsum, ysum;
    for (long long i = 0; i < n; i++){
        cin >> cords[i].first >> cords[i].second;
        cords[i].first+=10000; cords[i].second+=10000;
        yx[cords[i].second].push_back(cords[i].first);
        xy[cords[i].first].push_back(cords[i].second);
    }
    for (auto& v : yx){sort(v.second.begin(), v.second.end()); }
    for (auto& v : xy){sort(v.second.begin(), v.second.end()); }

    for (auto& v : yx){
        for (long long i = 0; i < v.second.size(); i++){
            xsum[v.first]+=v.second[i] - v.second[0];
        }
    }
    for (auto& v : xy){
        for (long long i = 0; i < v.second.size(); i++){
            ysum[v.first]+=v.second[i] - v.second[0];
        }
    }
    long long ans = 0;
    for (auto& v : yx){
        for (int i = 0; i < v.second.size(); i++){
            long long copyX = xsum[v.first] - (v.second[i] - v.second[0]) * (v.second.size() - (i + 1));
            if (i > 0){
                copyX+= (v.second[i] - v.second[i - 1]) * i;
            }
            int t = lower_bound(xy[v.second[i]].begin(), xy[v.second[i]].end(), v.first) - xy[v.second[i]].begin();
            t++;
            long long copyY = ysum[v.second[i]] - (v.first - xy[v.second[i]][0]) * (xy[v.second[i]].size() - t);
            if (t > 1){
                copyY += (t) * (xy[v.second[i]][t - 1] - xy[v.second[i]][t - 2]);
            }
            
            
            ans+= copyX * copyY;
        }
        
    }
    cout << ans%mod;

    
}