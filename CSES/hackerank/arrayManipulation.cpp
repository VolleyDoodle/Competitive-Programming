#include <bits/stdc++.h>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n,0);
    long len = queries.size();
    for (long i = 0; i < len; i++){
        arr[queries[i][0] - 1]+= queries[i][2];
        if(queries[i][1]<n) // checking for segmentation fault
        {
            // step 2 as described above
            arr[(queries[i][1])] = arr[(queries[i][1])]-queries[i][2]; 
        }
    }
    long runningSum = 0, ans = 0;
    for (long i = 0; i < n; i++){
        runningSum+=arr[i];
        ans = max(runningSum, ans);
    }
    
    return ans;
     
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, m;
    cin >> n, m;
    vector <vector <int>> rang;
    for (int i = 0; i < m; i++){
        int a, b, k;
        cin>> a >> b >> k;
        rang.push_back({a, b, k});
    }
    long crr = arrayManipulation(n, rang);
    cout << crr;
}