#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, cnt = 0;
    cin >> n;

    vector <int> curPos(n + 1), endPos(n + 1);
    vector <pair <int, int>> ans;
    for (int i = 1; i <= n; i++){
        int c;
        cin >> c;
        endPos[i] = c;
        curPos[i] = i;
    }
    for (int i = n; i >= 1; i--){
        int endCar = endPos[i];
        //in curPos, the endCar is guarenteed to be in front
        int indexCur = -1;
        for (int x = i; x >= 1; x--){
            if (curPos[x] == endCar){
                indexCur = x;
            }
        }
        //at index cur, the car can swap two times with everything before it and one with everything after
        for (int x = indexCur; x >= 2; x--){
            cnt++;
            ans.push_back({endCar, curPos[x - 1]});
            swap(curPos[x], curPos[x - 1]);
        }
        //going back to og spot
        for (int x = 1; x < indexCur; x++){
            cnt++;
            ans.push_back({curPos[x + 1], curPos[x]});
            swap(curPos[x], curPos[x + 1]);
        }
        //now just going to spot
        for (int x = indexCur; x < i; x++){
            cnt++;
            ans.push_back({curPos[x + 1], curPos[x]});
            swap(curPos[x], curPos[x + 1]);
        }
    }
    cout << cnt << "\n";
    for (auto& p : ans){
        cout << p.f << " " << p.s << "\n";
    }

}