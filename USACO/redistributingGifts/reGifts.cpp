#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 501;
int prefList[MAX_N][MAX_N];
//note that we can only make a win-win transaction (in problem statement)
//so we can make graph of all possible transactions
vector <vector <int>> connections;
vector <int> curGifts(MAX_N);
int main(){
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        curGifts[i] = i;
        for (int x = 0; x < n; x++){
            cin >> prefList[i][x];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= n; x++){
            //compare cows[i] and cows[x] gifts and see if when switched
            //both cows get betters gifts
            int inIndexI, inIndexX, swIndexI, swIndexX, allDone = 0;
            

            for (int j = 0; j < n; j++){    
                if (prefList[i][j] == curGifts[x]){ 
                    allDone++;
                    swIndexX = j;
                } if (prefList[x][j] == curGifts[i]){
                    allDone++;
                    swIndexI = j;
                } if (prefList[i][j] == curGifts[i]){
                    allDone++;
                    inIndexI = j;
                } if (prefList[x][j] == curGifts[x]){
                    allDone++;
                    inIndexX = j;
                }
                if (allDone == 4){ 
                    break;
                }
            }
            if (swIndexX < inIndexI && swIndexI < inIndexX){
                /*cout << "i: " << i << "| x: " << x << "\n";
                cout << "swIndexX: " << swIndexX << "| inIndexI: " << inIndexI << "\n";
                cout << "swIndexI: " << swIndexI << "| inIndexX: " << inIndexX << "\n";
                //swap can take place
                cout << "before: -> ";
                cout << "curGifts[i]: " << curGifts[i] << "| curGifts[x]: " << curGifts[x] << "\n";*/
                //swap(curGifts[i], curGifts[x]);
                connections.push_back({(inIndexI - swIndexX) + (inIndexX - swIndexI), swIndexX, swIndexI});
                /*cout << "after: ->";
                cout << "curGifts[i]: " << curGifts[i] << "| curGifts[x]: " << curGifts[x] << "\n";*/
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << curGifts[i] << '\n';
    }

    
    

}