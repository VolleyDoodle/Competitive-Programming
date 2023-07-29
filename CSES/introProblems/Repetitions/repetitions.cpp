#include <bits/stdc++.h>
using namespace std;

int main(){
    string dna;
    cin >> dna;
    int n = dna.size(), ans = 1, curAns = 1;
    char curChar = 'Z';
    for (int i = 0; i < n; i++){
        char temp = dna[i];
        if (curChar == temp){
            curAns++;
        } else{
            curChar = temp;  
            curAns = 1;
        }
        ans = max(ans, curAns);

    }
    cout << ans;

}