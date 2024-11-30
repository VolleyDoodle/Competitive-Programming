#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <int> years(n + 1);
    years[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> years[i];
    }
    sort(years.begin(), years.end());
    int x = years[n];
    years.push_back(x + (12 - x%12));
    
    k--;
    vector <pair <int, vector <int>>> arr(years.size() - 1, {0, vector<int>(2)});
    for (int i = 0; i < years.size() - 1; i++){
        int tempX = years[i]; int tempY = years[i + 1];
        if (tempX != 0) tempX+=(12 - tempX % 12);
        
        tempY-= (tempY % 12);
        arr[i].first = (tempY - tempX)/12 + 1;
        arr[i].second[0] = (years[i + 1] - tempY) + (tempX - years[i]);
        arr[i].second[1] = years[i+1] - years[i];
        //if (arr[i].first == 1){ arr[i].first--;}

    }
    sort(arr.begin(), arr.end(),[]
    (auto const& a, auto const& b){
        if (a.first == b.first){
            return a.second[0] < b.second[0];
        }
        return a.first < b.first;
    });
    int ans = 0;
    for (int i = arr.size() - 1; i >= 0; i--){
        if (k!= 0 && arr[i].first > 1){
            ans+=arr[i].second[0];
            k--;
            continue;
        }
        ans+=arr[i].second[1];

    }
    cout << ans;
    
}