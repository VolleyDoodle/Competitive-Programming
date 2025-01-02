#include <bits/stdc++.h>
using namespace std;
//unsolv3ed
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s;
    cin >> s;
    string vowels = "AEIOU";
    int vCount = 0, cCount = 0, nCount = 0, gCount = 0, yCount = 0;
    for (int i = 0; i < s.size(); i++){
        char t = s[i];
        if (vowels.find(t) != string::npos){
            vCount++;
        } else if (t == 'Y'){
            yCount++;
        } else if (t == 'N'){
            nCount++;
        } else if (t == 'G'){
            gCount++;
        } else{
            cCount++;
        }
    }

    //alright so basically if vowels are more than 2x cCount
    //gonna use n + g and ys
    //otherwise, 
    int ans = 0;
    while (true){
        if (vCount < 1){
            if (yCount >= 1){
                yCount--;
                vCount++;
            } else{
                break;
            }
        }
        if (cCount < 2){
            
        }
    }
}