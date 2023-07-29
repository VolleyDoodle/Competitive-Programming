#include <bits/stdc++.h>
using namespace std;

const int bigNum = pow(10, 1) + 1;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, ans = 0;
    cin >> n;
    map<int, int> tempA, importance;
    //memset(tempA, 0, bigNum * sizeof(int));
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        tempA[temp]+=temp;
    }
    map<int, int> tempB = tempA;
    for (auto element: tempB){
        importance[element.first] = element.second - (tempA[element.first + 1] + tempA[element.first - 1]);
    }
    while (true){
        int takeAwayIndex, takeAwayVal = INT_MIN;
        for (auto element: importance){
            //find max ai in importance and use that :)
            if (element.second > takeAwayVal){
                takeAwayVal = element.second;
                takeAwayIndex = element.first;
            }
        }

        ans+=takeAwayIndex;
        importance.erase(takeAwayIndex + 1); importance.erase(takeAwayIndex - 1);
        tempB[takeAwayIndex]-=takeAwayIndex;
        if (!tempB[takeAwayIndex]){
            importance.erase(takeAwayIndex);
        }
        //takeAwayIindex - 2 and +2 are affected by +1 and -1
        if (importance.count(takeAwayIndex + 2) && importance.count(takeAwayIndex + 3)){
            importance[takeAwayIndex+2] = -1;
        }
        if (importance.count(takeAwayIndex - 2) && importance.count(takeAwayIndex - 3)){
            importance[takeAwayIndex-2] = 1;
        }
        if (!importance.size()) break;
    }
    cout << ans;
    
}