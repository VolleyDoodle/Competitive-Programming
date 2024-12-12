#include <bits/stdc++.h>
using namespace std;
//fucking did this problem wrong
//also made it alot easier than its supposed to be
void solve(){
    long long n, x1;
    cin >> n >> x1;
    vector <long long> topLeft(n), bottomLeft(n);
    vector <pair <long long, long long>> topRight(n), bottomRight(n);
    for (int i = 0; i < n; i++){
        cin >> bottomLeft[i] >> topRight[i].second >> topRight[i].first;
        topLeft[i] = topRight[i].second;
        bottomRight[i].first = topRight[i].first;
        bottomRight[i].second = bottomLeft[i];
    }
    vector <long long> posSlopes, negSlopes;
    for (int i = 0; i < 4 * n; i++){
        long long t1;
        cin >> t1;
        (t1 > 0 ? posSlopes.push_back(t1) : negSlopes.push_back(t1));
    }
    if (posSlopes.size() != negSlopes.size()){
        cout << "-1";
        return;
    }
    //should be 2n positive slopes and 2n neg-slopes
    sort(posSlopes.begin(), posSlopes.end(), greater<>());
    sort(negSlopes.begin(), negSlopes.end());

    sort(topLeft.begin(), topLeft.end());
    sort(bottomLeft.begin(), bottomLeft.end());

    long long minUY = topLeft[0] - (posSlopes[0] * x1) , maxDY = bottomLeft[0] - (negSlopes[0] * x1);
    for (int i = 0; i < n; i++){
        //name is kind of confusing
        //but basically the miniumum upValue is the maximum of all values
        minUY = max(minUY, topLeft[i] - (posSlopes[i] * x1));
    }
    for (int i = 0; i < n; i++){
        maxDY = min(maxDY, bottomLeft[i] - (negSlopes[i] * x1));
    }

    vector <bool> visited(n, false);
    for (int i = n; i <= 2 * n - 1; i++){
        bool notFound = true;
        long long minCurUY, minCurIndex;
        for (int j = 0; j < n; j++){
            if (notFound && !visited[j]){
                minCurUY = topRight[j].second - (negSlopes[i] * topRight[j].first);
                minCurIndex = j;
                notFound = false;
                continue;
            }
            if (topRight[j].second - (negSlopes[i] * topRight[j].first) < minCurUY && !visited[j]){
                minCurUY = topRight[j].second - (negSlopes[i] * topRight[j].first);
                minCurIndex = j;
            }
        }
        visited[minCurIndex] = true;
        minUY = max(minUY, minCurUY);
    }   
    fill(visited.begin(), visited.end(), false);

    for (int i = n; i <= 2 * n - 1; i++){
        bool notFound = true;
        long long maxCurDY, maxCurIndex;
        for (int j = 0; j < n; j++){
            if (notFound && !visited[j]){
                    maxCurDY = bottomRight[j].second - (posSlopes[i] * bottomRight[j].first);
                    maxCurIndex = j;
                    notFound = false;
                    continue;
                }
            if (bottomRight[j].second - (posSlopes[i] * bottomRight[j].first) > maxCurDY && !visited[j]){
                maxCurDY = bottomRight[j].second - (posSlopes[i] * topRight[j].first);
                maxCurIndex = j;
            }
        }
        visited[maxCurIndex] = true;
        maxDY = min(maxDY, maxCurDY);
    }
    cout << minUY - maxDY;

}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
         solve();
        cout << "\n";
    }
}