#include <bits/stdc++.h>
using namespace std;
string fence;
void sums(vector <int>& v){
    for (int i = 0; i < 4; i++){
        v[i] = i + 1;
    }
}
int main(){
    /*int n, q;
    cin >> n >> q;
    cin >> fence;
    while (q--){

    }*/
    vector <int> v(4);
    fill(v.begin(), v.end(), 0);
    sums(v);
    cout << 'h';
}