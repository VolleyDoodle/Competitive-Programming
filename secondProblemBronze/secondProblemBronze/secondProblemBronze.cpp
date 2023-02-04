using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
string cows;
int n, k;
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int t;
    fin >> t;
    int g_arr[41], h_arr[41];
    char ans[10];
    for (int i = 0; i < t; i++) {
        fin >> n >> k; fin >> cows;
        fill(ans, ans + n, 'z');
        while (true) {
            for (int i = 0; i < n; i++) { ans[i] = 'x'; }
            
            for (int i = 0; i < n; i++) {
                //first use special array stuffs
                if (cows[i] == 'G') {
                    for (int x = max(0, i - k); x <= min(n - 1, i + k); x++) {
                        g_arr[x]++;
                    }
                }
                else if (cows[i] == 'H') {
                    for (int x = max(0, i - k); x <= min(n - 1, i + k); x++) {
                        h_arr[x]++;
                    }
                }

            }
            //now do find max point with most cows attracted
            int maxG = -1, maxH = -1;
            for (int i = 0; i < n; i++) {
                if (ans[i] != 'G' && ans[i] != 'H' && maxG == -1) { maxG = i; }
                else {
                    if (g_arr[i] > g_arr[maxG] && ans[i] != 'G' && ans[i] != 'H') { maxG = i; }
                }
            }
            for (int i = 0; i < n; i++) {
                if (maxH == -1 && i != maxG && ans[i] != 'G' && ans[i] != 'H') { maxH = i; }
                else {
                    if (h_arr[i] > h_arr[maxH] && ans[i] != 'G' && ans[i] != 'H' && i != maxG) { maxH = i; }
                }
            }

            if (h_arr[maxH] == 0 && g_arr[maxG] == 0) {
                for (int i = 0; i < n; i++) { fout << ans[i]; }
                fout << endl;
                break;
            }
            if (maxH == -1 && maxG == -1) {
                for (int i = 0; i < n; i++) { fout << ans[i]; }
                fout << endl;
                break;
            }
            for (int i = max(0, maxG - k); i <= min(n - 1, maxG + k); i++) {
                if (cows[i] == 'G') { cows[i] = 'D'; ans[i] = '.'; }
            }

            for (int i = max(0, maxH - k); i <= min(n - 1, maxH + k); i++) {
                if (cows[i] == 'H') { cows[i] = 'D'; ans[i] = '.'; }
            }

            ans[maxG] = 'G'; ans[maxH] = 'H';
        }
        
        
    }

}

