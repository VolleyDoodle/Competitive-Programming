#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> nums(n);
    vector <int> setOne, setTwo;
    for (int i = 1; i <= n; i++){
        nums[i - 1] = i;
    }
    long long dSum = (long long)(n + 1) * n;
    dSum/=2;
    if (dSum%2 == 1){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
        if ((n/2)%2 == 0){
            cout << n/2 << "\n";
            for (int i = 0; i < n/4; i++){
                cout << nums[i] << " " << nums[n - i - 1] << " ";
            }
            cout << "\n";
            cout << n/2 << "\n";
            for (int i = n/4; i < n/2; i++){
                cout << nums[i] << " " << nums[n - i - 1] << " ";
            }
        } else{
            cout << n/2 << "\n";
            int swapKey = (n - 1) - nums[n/2];
            swapKey/=2;
            setOne.push_back(nums[n - swapKey - 1]);
            setTwo.push_back(nums[swapKey]);
            setTwo.push_back(nums[n/2]);
            nums.erase(nums.begin() + n - swapKey - 1);
            nums.erase(nums.begin() + swapKey);
            nums.erase(nums.begin() + n/2 - 1);
            for (int i = 0; i < (n - 3)/2; i++){
                if (i%2 == 0){
                    setOne.push_back(nums[i]);
                    setOne.push_back(nums[(n - 4) - i]);
                } else{
                    setTwo.push_back(nums[i]);
                    setTwo.push_back(nums[(n - 4) - i]);
                }
            }
            for (int e: setOne){
                cout << e << " ";
            }
            cout << "\n";
            cout << n - n/2 << "\n";
            for (int e: setTwo){
                cout << e << " ";
            }
            
        }
    }
}