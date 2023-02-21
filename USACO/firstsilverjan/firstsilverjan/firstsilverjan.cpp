
#include <bits/stdc++.h>

using namespace std;

int check[1501][1501];
int grid[1501][1501];
int main()
{
    //ifstream cin("input.in");
    //ofstream fout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int tempp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for (int x = 0; x < n; x++) {
            //r = -1, d = -2
            if (temp[x] == 'R') { grid[i][x] = -1; }
            else if (temp[x] == 'D') { grid[i][x] = -2; }
        }
         cin >> tempp; grid[i][n] = tempp;
    }
    for (int x = 0; x < n; x++) {
        cin >> tempp;
        //cout << tempp << endl;
        grid[n][x] = tempp;
    }

    /*for (int i = 0; i <= n; i++) {
        for (int x = 0; x <= n; x++) {
            cout << grid[i][x] << " ";
        }
        cout << endl;
    }*/

    int q; cin >> q;

    for (int l = 0; l <= q; l++) {
        //fout << l << endl;
        
        int ans = 0;
        int cur = 0;
        int total_cur = 0;
        
        if (l > 0) {
            int flip_i, flip_j;
            cin >> flip_i >> flip_j;
            if (grid[flip_i - 1][flip_j - 1] == -1) {
                grid[flip_i - 1][flip_j - 1] = -2;
            }
            else {
                grid[flip_i - 1][flip_j - 1] = -1;
            }
        }
        //simulate!!!
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (check[y][x] == l) {
                    
                    int i = y; int j = x;
                    
                    //cur++;
                    while (true) {
                        if (i == n || j == n) {
                            //done
                            ans += grid[i][j] * cur;
                            break;
                        }
                        if (check[i][j] == l) {
                            cur++;
                            check[i][j]++;
                        }
                        
                        
                        
                        //cout << "ran" << endl;
                        if (grid[i][j] == -1) {
                            j++;     
                        }
                        else if (grid[i][j] == -2) {
                            i++;  
                        }

                        
                        
                    }
                }
                total_cur += cur;
                cur = 0;
                if (total_cur == n * n) {
                    break;
                }
                
            }
            if (total_cur == n * n) {
                cout << ans << endl;
                break;
            }

        }

        


    }
}

