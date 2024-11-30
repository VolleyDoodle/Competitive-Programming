#include <bits/stdc++.h>
using namespace std;
struct xy{
    int og, srt;
};
int main(){
    int n;
    cin >> n;
    vector <pair <xy, vector <int>>> sortGifts(n);
    vector <vector <int>> order(n);
    vector <int> ans(n);
    vector <bool> used(n + 1);
    fill(used.begin(), used.end(), 0);
    for (int i = 0; i < n; i++){
        for (int x = 0; x < n; x++){
            int ct;
            cin >> ct;
            if (ct == i + 1){
                sortGifts[i].first.srt = x;
                sortGifts[i].first.og = i;
            }
            sortGifts[i].second.push_back(ct);
        }
    }
    sort(sortGifts.begin(), sortGifts.end(), [](auto& a, auto& b){
        return a.first.srt < b.first.srt;
    });
    for (auto& element : sortGifts){
        for (int i = 0; i <= element.first.srt; i++){
            if (!used[element.second[i]]){
                used[element.second[i]] = true;
                ans[element.first.og] = element.second[i];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << '\n';
    }
}