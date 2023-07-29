#include <bits/stdc++.h>
using namespace std;

long long ans;
void queenExpansion(char *chessboard[], int i, int x){
    chessboard[i][x] = 'B';
    return;
}
void solve(char *chessboard[]){

    queenExpansion(chessboard, 0, 0);
    /*for (int i = 0; i < 8; i++){
        for (int x = 0; x < 8; x++){
            if (chessboard[i][x] == '.'){
                //queen can be placed here
                chessboard[i][x] = 'Q';
                
                //now place 'Q' wherever new queen takes place and repeat cycle
            }
        }
    }*/
}
int main(){
    char **chessboard;

    chessboard = (char **)calloc(8, sizeof(char *));
    for (int i = 0; i < 8; i++) {
        chessboard[i] = (char *)calloc(8, sizeof(char));
    }

    for (int i = 0; i < 8; i++){
        for (int x = 0; x < 8; x++){
            cin >> chessboard[i][x];
        }
    }
    
    solve(chessboard);
      
}