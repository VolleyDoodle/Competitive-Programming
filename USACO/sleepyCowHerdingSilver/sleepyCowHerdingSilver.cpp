#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> arr;
void findMinMoves(){
    if (arr[n-2] - arr[0] == n - 2 && arr[n-1] - arr[n - 2] > 2){
        cout << 2 << "\n";
        return;
    }
    if (arr[n - 1] - arr[1] == n - 2 && arr[1] - arr[0] > 2) {
        cout << 2 << "\n";
        return;
    }
    int tempAns = INT_MAX;
    int left = 0, right = 0;
    while (left <= right && right < n){
        while (arr[right] - arr[left] >= n){
            left++;
        }
        tempAns = min(tempAns, n - (right - left + 1));
        right++;

    }
    cout << tempAns << "\n";
}
void findMaxMoves(){
    cout << max(arr[n - 2] - arr[0], arr[n - 1] - arr[1]) - (n - 2) << "\n";
}
int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    findMinMoves();
    findMaxMoves();

}