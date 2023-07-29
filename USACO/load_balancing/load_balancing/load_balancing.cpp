#include <bits/stdc++.h>
using namespace std;

//Horizontal line = Hline, vertical line = Vline
int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = INT_MAX, tempAns; 
    cin >> n;
    vector <pair <int, int>> cords(n), aboveLine, belowLine;
    for (int i = 0; i < n; i++){
        cin >> cords[i].first >> cords[i].second;
    }
    sort(cords.begin(), cords.end());
    //basically just do it lol
    for (int i = 0; i < n; i++){
        int Hline = cords[i].second + 1;
        for (int x = 0; x < n; x++){
            if (cords[x].second > Hline){
                aboveLine.push_back(cords[x]);
            } else{
                belowLine.push_back(cords[x]);
            }
            //cords[x].second > Hline ? aboveLine.push_back(cords[x]) : belowLine.push_back(cords[x]);
        }
        int aboveLen = aboveLine.size(), belowLen = belowLine.size();
        int upperIndex = 0, lowerIndex = 0;
        for (int x = 0; x < n - 1; x++){
            int Vline = cords[x].first + 1;
            while (aboveLine[upperIndex].first < Vline && upperIndex < n){
                upperIndex++;
            } while (belowLine[lowerIndex].first < Vline && lowerIndex < n){
                lowerIndex++;
            }
            tempAns = max(max(upperIndex, aboveLen - upperIndex), max(lowerIndex, belowLen  - lowerIndex));
            ans = min(ans, tempAns);
        }
        aboveLine.clear(); belowLine.clear();                                                                                                                                                                                
        

    }
    cout << ans;

}

