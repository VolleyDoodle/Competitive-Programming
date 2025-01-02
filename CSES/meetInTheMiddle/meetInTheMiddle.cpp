#include <bits/stdc++.h>
using namespace std;
long long x;
int n;
vector <long long> firstHalf, secondHalf;
void subsetCreation(vector <int>& nums, int half){
    int n = nums.size();
    for (int i = 0; i < (1LL << n); i++){
        long long sum = 0;
        //now the binary expression of i represents a permutation
        //now check every bit of i, and add to our permutation if it is 1
        for (int x = 0; x < n; x++){
            if (i & (1 << x)){
                sum+=nums[x];
            }
        }  
        if (half == 1) firstHalf.push_back(sum);
        else secondHalf.push_back(sum);

    }
}
int main(){
    //cout << (1 << 4) << "\n";
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    cin >> n >> x;
    vector <int> firstNums(n/2), secondNums(n - n/2);
    for (int i = 0; i < n/2; i++){
        cin >> firstNums[i];
    }
    for (int i = n/2; i < n; i++){
        cin >> secondNums[i - n/2];
    }
    subsetCreation(firstNums, 1);
    subsetCreation(secondNums, 2);
    sort(secondHalf.begin(), secondHalf.end());

    long long ans = 0;
    for (long long& num : firstHalf){
        ans += upper_bound(secondHalf.begin(), secondHalf.end(), x - num) - lower_bound(secondHalf.begin(), secondHalf.end(), x - num);
        
    }
    cout << ans;

    
}