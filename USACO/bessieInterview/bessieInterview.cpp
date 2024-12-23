#include <bits/stdc++.h>
using namespace std;
//137462
//300000
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <long long>  times(n);
    map <long long, vector <long long>> sameTime;
    //any time any number of cows end at the same time,
    //they are sameTime/linked together
    //need some fast way to keep track of the links
    vector <long long> farmerEndTimes(k);
    for (int i = 0; i < n; i++){
        
        cin >> times[i];
        if (i < k) farmerEndTimes[i] = times[i];
    }
    //farmers represent the endtimes of each cow
    //pririt
    //priority_queue<pair<long long, int>, vector <pair <long long, int>>, greater<pair <long long, int>>> timeFarmers;
    priority_queue<long long, vector <long long>, greater<long long>> timeFarmers;
    for (int i = 1; i <= k; i++){
        timeFarmers.push(0);
    }
    for (int i = 0; i < n; i++){
        long long current = timeFarmers.top();
        timeFarmers.pop();
        timeFarmers.push(current + times[i]);
        sameTime[current + times[i]].push_back(current);
    }
    long long finalEnd = timeFarmers.top();
    set <long long> visited;
    queue <long long> endTimes;
    endTimes.push(finalEnd);
    /*long long sum = 0;
    for (auto& l : sameTime){
        sum += l.second.size();
    }
    cout << sum;*/
    while (endTimes.size()){
        long long cur = endTimes.front();
        endTimes.pop();
        visited.insert(cur);
        for (long long sTime : sameTime[cur]){
            if (visited.count(sTime) == 0){
                endTimes.push(sTime);
            }
        }
    }
    cout << finalEnd << "\n";
    for (long long& farmer : farmerEndTimes){
        cout << visited.count(farmer);
    }
    
    

}