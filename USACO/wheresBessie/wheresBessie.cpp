#include <bits/stdc++.h>
using namespace std;
//using cords to practice structs (could use pairs)
struct cords{
    int x, y;
};
struct trbl{
    int trx, trY, blx, bly;
};
vector <vector <char>> image;
vector <vector <bool>> visited;
vector <trbl> posAnswers;
cords topRight, bottomLeft;
char contChar;
int n;
void floodfill(int x, int y){
    //commented out code also works but below code is much easier to write
    if (image[y][x] != contChar || x > topRight.x || x < bottomLeft.x || y > bottomLeft.y || y < topRight.y || visited[y][x]){
        return;
    }
    visited[y][x] = true;
    floodfill(x + 1, y);
    floodfill(x, y + 1);
    floodfill(x - 1, y);
    floodfill(x, y - 1);
    /*if (image[y][x + 1] == contChar && x + 1 <= topRight.x && !visited[y][x + 1]){
        floodfill(x + 1, y);
    }
    if (image[y + 1][x] == contChar && y + 1 <= bottomLeft.y && !visited[y + 1][x]){
        floodfill(x, y + 1);
    }
    if (image[y][x - 1] == contChar && x - 1 >= bottomLeft.x && !visited[y][x - 1]){
        floodfill(x - 1, y);
    }
    if (image[y - 1][x] == contChar && topRight.y <= y - 1 && !visited[y - 1][x]){
        floodfill(x, y - 1);
    }*/
    
}
bool checkPcl(){
    //first got to see if there are two colors and each possible location of each color to dfs
    //check for two colors
    set <char> colors;
    for (int i = bottomLeft.x; i <= topRight.x; i++){
        for (int x = topRight.y; x <= bottomLeft.y; x++){
            colors.insert(image[x][i]);
        }
    }
    if (colors.size() != 2){
        return false;
    }
    for (int i = 0; i < n + 2; i++){
        fill(visited[i].begin(), visited[i].end(), 0);
    }
    char color1 = *colors.begin(), color2 = *colors.begin() + 1;
    int color1Amt = 0, color2Amt = 0;

    for (int i = bottomLeft.x; i <= topRight.x; i++){
        for (int x = topRight.y; x <= bottomLeft.y; x++){
            if (!visited[x][i]){
                if(image[x][i] == color1){color1Amt++;}
                else{color2Amt++;}
                int newX = i; int newY = x;
                contChar = image[x][i];
                floodfill(newX, newY);
                    
            }
        }
    }
    if ((color1Amt == 1 && color2Amt >= 2) || (color2Amt == 1 && color1Amt >=2)){
        trbl temp;
        temp.trx = topRight.x; temp.trY = topRight.y;
        temp.blx = bottomLeft.x; temp.bly = bottomLeft.y;
        posAnswers.push_back(temp);
        return true;
    }
    return false;
    
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    cin >> n;
    image.resize(n + 2);
    visited.resize(n + 2);
    for (int i = 0; i < n + 2; i++){
        image[i].resize(n + 2);
        visited[i].resize(n + 2);
        image[i][0] = '['; image[i][n + 1] = '[';
    }

    fill(image[0].begin(), image[0].end(), '[');
    fill(image[n + 1].begin(), image[n + 1].end(), '[');

    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= n; x++){
            cin >> image[i][x];
        }
    }
    //generate all possibililites of topRight and bottomLeft cords
    //going up on y, is going down
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= n; x++){
            //topRight = (i, x)
            for (int j = i; j >= 1; j--){
                for (int k = x; k <= n; k++){
                    //bottomLeft = (j, k)
                    topRight.x = i; topRight.y = x;
                    bottomLeft.x = j; bottomLeft.y = k;
                    ans+=checkPcl();
                }
            }
        }
    }
    //now check for pcl in other pcl
    vector <bool> alreadyIn(posAnswers.size());
    fill(alreadyIn.begin(), alreadyIn.end(), 0);
    for (int i = 0; i < posAnswers.size(); i++){
        trbl element1 = posAnswers[i];
        for (int x = 0; x < posAnswers.size(); x++){
            trbl element2 = posAnswers[x];
            if (i != x && !alreadyIn[x]){
                //check if element1 contains element2
                if (element1.trx >= element2.trx && element1.trY <= element2.trY && element1.blx <= element2.blx && element1.bly >= element2.bly){
                    ans--;
                    alreadyIn[x] = true;
                }
            }
        }
    }
    cout << ans;

}