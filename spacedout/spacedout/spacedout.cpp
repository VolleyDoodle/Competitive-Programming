#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int a[1000][1000];
int main()
{
    ifstream fin("spaced.in");
    ofstream fout("spaced.out");
    int n, temp_ans = 0, temp_ans2 = 0;
    int sum[2];
    sum[0] = sum[1] = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            cin >> a[i][x];
        }
    }   
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            sum[x % 2] += a[i][x];
        }
        temp_ans += max(sum[0], sum[1]);
        sum[0] = sum[1] = 0;
    }
    //fout << temp_ans;
    sum[0] = sum[1] = 0;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            sum[x % 2] += a[x][i];
        }
        temp_ans2 += max(sum[0], sum[1]);
        sum[0] = sum[1] = 0;
    }
    //fout << temp_ans2;
    cout << max(temp_ans, temp_ans2);


}
