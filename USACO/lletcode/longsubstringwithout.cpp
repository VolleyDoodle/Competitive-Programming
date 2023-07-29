#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> checkDupl;
        checkDupl[s[0]] = true;
        string ans = "", curAns = "";
        int left = 0, right = 1, n = s.size();
        curAns = s[0]; ans = s[0];
        while (right < n){
            //cout << "curAns: " << curAns << endl;
            if (checkDupl[s[right]]){
                //cout << "if statement is running!" << endl;
                checkDupl[s[left]] = false; left++; 
                curAns.erase(0, 1);
            }
            else{
                curAns+=s[right];
                checkDupl[s[right]] = true;
                if (curAns.size()> ans.size()){
                    ans = curAns;
                }
                right++;

            }
        }
        return ans.size();
}

int main(){
    string temp;
    cin >> temp;
    cout << lengthOfLongestSubstring(temp);
}

