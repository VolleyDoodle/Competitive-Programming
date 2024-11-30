
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    cout << "sdl";
    int n, ans = 0, rExp, temp_ans, exploded;
    int pExploded;
    bool done;
    fin >> n;
    int a[101];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    sort(a, a + n);
    //algorithm
    for (int i = 0; i < n; i++) {
        //explode a[i]
        temp_ans = 1;
        exploded = a[i];
        done = false;
        rExp = 1;
        //two parts (in front and back)
        for (int x = i; x < n; x++) {
            if (x == i) { continue; }
            for (int y = x; y < n; y++) { //search using rExp figures out farthest explosion
                if (a[y] <= exploded + rExp && a[y] > exploded) {
                    temp_ans++;
                    done = true;
                    pExploded = a[y];
                }
                else { break; }
            }
            if (done) {
                rExp++; exploded = pExploded; done = false;
            }            

        }
        rExp = 1;
        exploded = a[i];
        done = false;
        for (int x = i; x >= 0; x--) {
            if (x == i) { continue; }
            for (int y = x; y >=0; y--) { //search using rExp figures out farthest explosion
                if (a[y] >= exploded - rExp && a[y] < exploded) {
                    temp_ans++;
                    done = true;
                    pExploded = a[y];
                }
                else { break; }
            }
            if (done) { 
                rExp++; exploded = pExploded; done = false;
            }
        }
        ans = max(ans, temp_ans);

    }
    fout << ans;

}

