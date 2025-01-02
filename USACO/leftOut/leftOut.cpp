#include <bits/stdc++.h>
//lokwey just carrara code 
using namespace std;
bool isEqual(vector<int>& a, vector<int>& b){
    bool flipped = (a[0] != b[0]);
    for (int i = 0; i < a.size(); i++){
        if (flipped && a[i] == b[i]) return false;
        else if (!flipped && a[i] != b[i]) return false;
    }
    return true;
}
int main(){
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);
    int n;
    cin >> n;
    vector <vector <int>> grid(n, vector <int>(n));
    //1 = R, -1 = L
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char t;
            cin >> t;
            grid[i][j] = (t == 'R' ? 1 : -1);
        }
    }
    //basically everything has to be the same row over and over again (could be flipped)
    //and then if there is an exactly 1 odd one out row, that row can only have 1 cell that is different from the usual
    //take the first row, check with all other rows
    //first case -> a different row has only 1 odd
    //second case -> the first row is the odd one out which means it should 
    vector <int> a = grid[0], b = grid[1];
    int rowNum = 1;
    //basically finds first "differing" row
    while(isEqual(a, b)){
        rowNum++;
        b = grid[rowNum];
        //if (rowNum == n) break; //this should technically never run as it is impossible for all to be equal
    }
    //now rowNum is the # row of the first differing row from grid[0]
    //so now, a grid that is possible, either all the other rows are equal to b or a exepct 1
    int cnt1 = 0, cnt2 = 0; //cnt 1 for a, cnt2 for b
    for (int i = 0; i < n; i++){
        if (isEqual(a, grid[i])) cnt1++;
        else if (isEqual(b, grid[i])) cnt2++;
        else{
            cout << -1;
            return 0;
        }
    }
    if (cnt1 > 1 && cnt2 > 1){
        cout << -1;
        return 0;
    }
    //now just need to find loc of the cow
    //just gotta compare a and b atp
    for (int i = 0; i < n; i++){
        a[i]*=-1;
        if (isEqual(a, b)){
            if (cnt1 == 1){
                cout << 1 << " " << i + 1;
            } else{
                cout << rowNum + 1 << " " << i + 1;
            }
            return 0;
        }
        a[i]*=-1;
    }
    cout << -1;

}