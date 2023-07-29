#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, l;
    cin >> n >> l;
    vector <int> cows(n), orders(l);
    //0 == 1 (cow)
    for (int i = 0; i < n; i++){
        cows[i] = i;
    }
    for (int i = 0; i < l; i++){
        cin >> orders[i];
    }
    int curCowIndex = 0, curOrder , curOrderIndex = 0;
    while (cows.size() > 1){
        curOrder = orders[curOrderIndex];
        while (curCowIndex + curOrder > n){
            curCowIndex = curCowIndex - n;
        }
        cows.erase(cows.begin() + curCowIndex + curOrder - 1);
        curCowIndex+=curOrder - 1;
        n--;
        curOrderIndex++;
        if (curOrderIndex == l){curOrderIndex = 0;}
    }
    cout << cows[0] + 1;
}