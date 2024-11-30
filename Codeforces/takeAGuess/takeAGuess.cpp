#include <bits/stdc++.h>
using namespace std;

int calc(int i, int j){
    //use info that (a + b) = (a || b) + (a && b)
    //then some basic alebgra
    int andAns, orAns;
    cout << "and " << i << " " << j << "\n";
    fflush(stdout);
    cin >> andAns;
    cout << "or " << i << " " << j << "\n";
    fflush(stdout);
    cin >> orAns;
    return andAns + orAns;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector <int > arr(n + 1);
    int a12 = calc(1, 2), a23 = calc(2, 3), a13 = calc(1, 3);
    arr[1] = (a12 - a23 + a13)/2;
    arr[2] = a12 - arr[1];
    arr[3] = a23 - arr[2];
    for (int i = 4; i <= n; i++){
        int t1 = calc(1, i);
        arr[i] = t1 - arr[1];
    }
    sort(arr.begin() + 1, arr.end());
    cout << "finish " << arr[k] << "\n";

}