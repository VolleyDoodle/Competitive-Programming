#include <bits/stdc++.h>
using namespace std;
int n;
vector <pair <int, int>> cows;
vector <vector <bool>> cowAtLoc;
vector <vector<int>> adjCows; //stroing the # of adjacent cows at location
//cows in range of (-500, 1500) by (-500, 1500)
//so 2000x2000 essentially
//max time 4 * 10^6, not that much :)
//solution does not work b/c of overcounting (adjacent cows overlap and can overcount)
//i can use a set!! with all the previous reactions to make sure nothing is double counted
set <vector <int>> setX, setY;

int curAns;
void addCow(int x, int y);
void adjust(int x, int y){
    //updates adjCows list
    // if any adj cows already == 4, then same exact answer - 1 from last time
    //int x = cows[cowIndex].first; int y = cows[cowIndex].second;
    
    if (adjCows[y][x] != -1){
        if (adjCows[y][x] == 3){

            addCow(x, y);
        }
        return;
    }
    adjCows[y][x] = 0;
    if (adjCows[y][x + 1] != -1 && !setX.count({y, x, x + 1})) {
        setX.insert({y, x, x + 1});
        adjCows[y][x]++; adjCows[y][x + 1]++;
        adjust(x + 1, y);
    }
    if (adjCows[y][x - 1] != -1 && !setX.count({y, x -1, x})) {
        setX.insert({y, x - 1, x});
        adjCows[y][x]++; adjCows[y][x - 1]++;
        adjust(x - 1, y);
    }
    if (adjCows[y - 1][x] != -1 && !setY.count({x, y - 1, y})) {
        setY.insert({x, y - 1, y});
        adjCows[y][x]++; adjCows[y - 1][x]++;
        adjust(x, y - 1);
    }
    if (adjCows[y + 1][x] != -1 && !setY.count({x, y, y + 1})) {
        setY.insert({x, y, y + 1});
        adjCows[y][x]++; adjCows[y + 1][x]++;
        adjust(x, y + 1);
    }
    adjust(x, y);
    
}
void addCow(int x, int y){
    if (adjCows[y][x + 1] == -1) {
        curAns++;
        adjust(x + 1, y);
    }
    if (adjCows[y][x - 1] == -1) {
        curAns++;
        adjust(x - 1, y);
    }
    if (adjCows[y - 1][x] == -1) {
        curAns++;
        adjust(x, y - 1);
    }
    if (adjCows[y + 1][x] == -1) {
        curAns++;
        adjust(x, y + 1);
    }
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    cin >> n;
    cows.resize(n);
    for (int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
        cows[i].first+=1004; cows[i].second+=1004;
        //cows[i].first+=1; cows[i].second+=1;
    }
    //cowAtLoc.resize(9, vector <bool>(9, false));
    adjCows.resize(3000, vector <int>(3000, -1)); //-1 means no cow is there
    vector <int> ans(n + 1, 0);
    //essentially need two functions
    //first one (only calls in unvisited cow)
    //second one (only calls if 3 adjacet) (and adds cow)
    for (int i = 0; i < n; i++){
        //adding cow i to the pasture woohoo!!
        curAns = ans[i];
        if (adjCows[cows[i].second][cows[i].first] != -1){
            cout << --curAns << "\n";
        } else{
            //unvisited call adjust
            adjust(cows[i].first, cows[i].second);
            cout << curAns << "\n";
        }
        ans[i + 1] = curAns;
        
    }
}