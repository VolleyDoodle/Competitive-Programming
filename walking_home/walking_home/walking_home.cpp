
#include <iostream>
using namespace std;
int solve_one(int n) {
    int ans = 0;
    bool right = true, left = true;
    char data[50][50];
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            cin >> data[i][x];
            if (i == 0 && data[i][x] == 'H') { right = false; }
            if (i == n - 1 && data[i][x] == 'H') { left = false; }
        }
        if (data[i][0] == 'H') { left = false; }
        if (data[i][n - 1] == 'H') { right = false; }
        
    }
    ans += left; ans += right;
    return ans;
}
int solve_two(int n) {
    char data[50][50];
    int work_one = 1, work_two = 1, ans = 0;
    //take input
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            cin >> data[i][x];
        }
    }
    //first case: bessie goes along the top then turns downwards and then goes to bottom right
    
    for (int i = 0; i < n ; i++) {
        if (data[0][i] == 'H') { work_one = 0; }
        for (int x = 0; x < n; x++){
            if (data[x][i] == 'H') { work_two = 0; }
        }
        for (int y = i; y < n; y++) {
            if (data[n - 1][y] == 'H') { work_two = 0; }
        }
        ans += work;
    }
    //second case: bessie goes along the left side turns sideways and then goes down to bottom right
    for (int i = 0; i < n; i++) {
        if (data[i][0] == 'H') { work = 0; }
        for (int x = 0; x < n; x++) {
            if (data[i][x] == 'H') { work = 0; }
        }
        for (int y = i; y < n; y++) {
            if (data[x])
        }
    }
}

int main()
{
    int t;
    int n, k;
    cin >> t;
    for (int u = 0; u < t; u++) {
        cin >> n >> k;
        if (k == 1) { cout << solve_one(n) << endl; };
        if (k == 2) { cout << solve_two(n) << endl; }
        if (k == 3) { cout << solve_three(n) << endl; }
    }
}
