#include <bits/stdc++.h>
using namespace std;

int main(){
    string og;
    cin >> og;
    unordered_map<char, int> amtLetters;
    for (char t: og){
        amtLetters[t]++;
    }
    if (og.size()%2 == 0){
        string ans = "";
        for (pair <char, int> element : amtLetters){
            if (element.second%2 == 1){
                cout << "NO SOLUTION";
                exit(0);
            }
            ans+= string(element.second/2, element.first);
        }
        cout << ans;
        reverse(ans.begin(), ans.end());
        cout << ans;

        //just generate easy!!
    } else{
        string ans = "";
        char oddChar;
        int oddCount = 0, oddAmt;
        for (pair <char, int> element : amtLetters){
            if (element.second%2 == 0){
                ans+= string(element.second/2, element.first);
                continue;
            }
            if (oddCount != 0){
                cout << "NO SOLUTION";
                exit(0);
            }
            oddCount++; oddAmt = element.second; oddChar = element.first;
        }
        cout << ans << string(oddAmt, oddChar);
        reverse(ans.begin(), ans.end());
        cout << ans;

    }
    

}