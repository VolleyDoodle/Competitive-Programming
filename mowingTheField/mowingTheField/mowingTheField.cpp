

#include <iostream>
using namespace std;

int main()
{
    int n, x = 1000, y = 1000;
    bool graph[2001][2001];
    for (int i = 0; i <= 2001; i++) {
        for (int x = 0; x <= 2001; x++) {
            graph[i][x] = false;
        }
    }
    graph[x][y] = true;
    char d, a;
    cin >> n;
    for (int g = 0; g < n; g++) {
        cin >> d >> a;
        for (int i = 0; i < a; i++) {
            if (d == 'N'){
                if (graph[y + i][x] == true){ }
            }
            if (d == 'S'){}
            if (d == 'E'){}
            else{ }
        }
    }
}


