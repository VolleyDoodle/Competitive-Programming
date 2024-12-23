#include <bits/stdc++.h>
using namespace std;
vector <bool> visited;
vector <vector <int>> graph;

void dfs(long long curFarmer){
    visited[curFarmer] = true;
    for (int nxtFarmer : sameTime[curFarmer]){
        if (!visited[nxtFarmer]){
            dfs(nxtFarmer);
        }
    }
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector <long long>  times(n);
    map <<long long>, vector <int>> sameTime;
    //any time any number of cows end at the same time,
    //they are sameTime/linked together
    //need some fast way to keep track of the links
    //
    graph.resize(k + 1);
    for (long long i = 0; i < n; i++){
        cin >> times[i];
    }
    //farmers represent the endtimes of each cow
    //pririt
    priority_queue<pair<long long,long long>, vector <pair <long long, long long>>, greater<pair <long long, long long>>> timeFarmers;
    for (long long i = 1; i <= k; i++){
        timeFarmers.push({0, i});
    }
    for (long long i = 0; i < n; i++){
        auto current = timeFarmers.top();
        timeFarmers.pop();
        timeFarmers.push({current.first + times[i], current.second});
        sameTime[current.first + times[i]].push_back(current.second);
    }
    auto finalFarmer = timeFarmers.top();
    visited.resize(k + 1, false);
    
    dfs(finalFarmer.second);
    cout << finalFarmer.first << "\n";
    for (long long i = 1; i <= k; i++){
        cout << visited[i];
    }
    
    

}