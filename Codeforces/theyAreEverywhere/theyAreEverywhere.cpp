#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> keepTrack(58, 0);
    set <char> neededLetters, curLetters;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        neededLetters.insert(s[i]);
    }
    int left = 0, right = 0;
    keepTrack[s[0] - 'A']++;
    curLetters.insert(s[0]);
    int ans = n;
    while(right <= n - 1){
        if (curLetters.size() == neededLetters.size()){
            ans = min(ans, right - left + 1);
        }
        if (keepTrack[s[left] - 'A'] - 1 > 0 || curLetters.size() == neededLetters.size()){
            
            keepTrack[s[left] - 'A']--;
            if (keepTrack[s[left] - 'A'] == 0){
                curLetters.erase(s[left]);
            }
            left++;

        }
        if (curLetters.size() != neededLetters.size()){
            right++;
            curLetters.insert(s[right]);
            keepTrack[s[right] - 'A']++;
        }
        
    }
    cout << ans;
}