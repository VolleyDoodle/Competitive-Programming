#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long runningSum = 0; int temp; 
    for (int i = 0; i < n - 1; i++){
        cin >> temp; runningSum+=temp;
    }
    //cout << ((float) n)/2;
    long long totalSum = ((long long)n * ((long long)n + 1))/2;
    int ans =  totalSum - runningSum;
    cout << (ans);
    
}