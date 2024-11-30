#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
void sumOfv(vector <int> a){
    
    long long sumOfIndex = 0, tempAns = 0;
    int curNum = a[0], curCount = 0;
    
    for (int i = 0; i < n; i++){
        if (a[i] > curNum){

            tempAns+= (curCount * (i + 1)) - sumOfIndex;
            curCount = 0; sumOfIndex = 0;
            curNum = a[i];
            continue;
        }
        curNum = a[i];
        sumOfIndex+=i; curCount++;

    }
    ans +=tempAns;
}
int main(){

    cin >> n;
    vector <int> b(n);
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    sumOfv(b);
    reverse(b.begin(), b.end());
    sumOfv(b);
    cout << ans;

    


}