#include <bits/stdc++.h>
using namespace std;

//since it is always possible for one cow to be at all the grazings
//that means, that starting from the first grazing, all other grazings are possible to attend to
//essentially, for one cow, all you have to look at is...
//the grazing before and after
//it the cow can go to both, then it can to any because of my second comment
//also just leave distance as squared rather htan comparing with doubles
long long distance(long long x, long long y, vector <long long>& v2){
    long long distance2 = (x - v2[1]) * (x - v2[1]) + (y - v2[2]) * (y - v2[2]);
    //double distanceLin = sqrt(distance2);
    return distance2;
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int g, n;
    cin >> g >> n;
    vector <vector <long long>> grazings;
    for (int i = 0; i < g; i++){
        long long x, y, t;
        cin  >> x >> y >> t;
        grazings.push_back({t, x, y});
    }
    sort(grazings.begin(), grazings.end());
    //assuming all cows are innoncent at start
    int ans = n;
    for (int i = 0; i < n; i++){
        long long x, y, t;
        cin >> x >> y >> t;
        auto it1 = upper_bound(grazings.begin(), grazings.end(), vector<long long>{t, x, y});
        auto it2 = upper_bound(grazings.begin(), grazings.end(), vector<long long>{t, x, y});
        //it1 and it2 return the grazing that happens right after this cow's alibi
        //vector <long long> v1 = *it1, v2 = *it2;
        if (it1 == grazings.begin()){
            //if it1 is the first element of the array, that means this cow's time is before the first grazing
            //no grazing before this cow
            //so just have to check the after grazing which is upper_bound
            vector <long long> v2 = *it2;
            if (distance(x, y, v2) <= abs(t - v2[0]) * abs(t - v2[0])){
                ans--;
            }
        } else if (it2 == grazings.end()){
            //if there are no grazings that end after this cow's time
            //so have to check from the grazing before
            it1--;
            vector <long long> v1 = *it1;
            if (distance(x, y, v1) <= abs(t - v1[0]) * abs(t - v1[0])){
                ans--;
            }
        } else{
            it1--;
            vector <long long> v1 = *it1;
            vector <long long> v2 = *it2;
            if (distance(x, y, v1) <= abs(t - v1[0]) * abs(t - v1[0]) && distance(x, y, v2) <= abs(t - v2[0]) * abs(t - v2[0])){
                ans--;
            }
            /*if ( distance(x, y, v2) <= abs(t - v2[0])){
                ans--;
            }*/
        }
    }
    cout << ans;


}