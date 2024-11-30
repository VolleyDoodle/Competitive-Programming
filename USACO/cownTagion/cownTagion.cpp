#include <bits/stdc++.h>
using namespace std;
const int bigNum = pow(10, 5) + 1;
int n, ans = 0;
vector <vector <int>> roads(bigNum);
vector <bool> visited(bigNum);
//vector <int> subTreeSums(bigNum); //
vector <int> numOfCows(bigNum); //stores amt of cows at each farm
/*void findSums(int parentNode){
    visited[parentNode] = true;
    for (int childNode : roads[parentNode]){
        if (!visited[childNode]){
            findSums(childNode);
            subTreeSums[parentNode]+=subTreeSums[childNode];
        }
    }
}*/   
void dfs(int parentNode){
    visited[parentNode] = true;
    int numOfChild = roads[parentNode].size();
    if (parentNode!=1) numOfChild--;
    while (numOfCows[parentNode] <= numOfChild){
        ans++;
        numOfCows[parentNode]*=2;
    }
    for (int childNode : roads[parentNode]){
        if (!visited[childNode]){
            numOfCows[parentNode]--;
            numOfCows[childNode]++;
            ans++;
            dfs(childNode);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    fill(numOfCows.begin(), numOfCows.end(), 0);
    numOfCows[1] = 1;
    //fill(visited.begin(), visited.end(), 0);
    //fill(subTreeSums.begin(), subTreeSums.end(), 1);
    for (int i = 0; i < n - 1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        roads[v1].push_back(v2);
        roads[v2].push_back(v1);
    }
    //findSums(1);
    fill(visited.begin(), visited.end(), 0);
    dfs(1);
    cout << ans;
}