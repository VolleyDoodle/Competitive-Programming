#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
//alright, so basically just finding k shortest paths
//for this probelm, every node stores the k shortest paths
//how do we do this?
//normal dijkistra to go through the graph
//because, realize that dijkistra is a greedy algo and will naturally build shortest paths
//however, since we need k of them, the moment when the our new path is greater than the worst kth path for that node
//we stop and now technically that node is "relaxed" 
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    long long n, m, k;
    cin >> n >> m >> k;
    vector <vector <pair <long long, long long>>> graph(n + 1);
    
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    priority_queue <pair <long long, long long>, vector <pair <long long, long long>>, greater<>> pq;
    vector <priority_queue <long long, vector <long long>>> bes(n + 1);
    /*for (int i = 1; i <= n; i++){
        for (int x = 0; x < k; x++){
            bes[i].push(1e18);
        }
    }*/
    //bes[1].pop();
    bes[1].push(0);
    //pq is {weight, id}
    //graph is {id, weight}
    pq.push({0, 1});
    while (!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        //below line makes huge improvement to program in terms of speed
        //why?
        //basically just says that this path is pointless as they are already better stuff
        //but when the FUCK does this shit even run??
        if (cur.first > bes[cur.s].top()){
            //basically just ends early when this current path is worse than our already worst path
            //just makes it faster ig and reduces uncessary computation
            continue;
            //cout << "I RAN " << cur.s << "\n";
        }
        for (auto& e : graph[cur.s]){
            if (bes[e.f].size() < k){
                bes[e.f].push(cur.f + e.s);
                pq.push({cur.f + e.s, e.f});
            }
            else if (cur.f + e.s < bes[e.f].top()){
                //new shorter path
                bes[e.f].pop();
                bes[e.f].push(cur.f + e.s);
                pq.push({cur.f + e.s, e.f});
            }
        }
        
    }
    vector <long long> ans(k);
    for (int i = k - 1; i >= 0; i--){
        ans[i] = bes[n].top();
        bes[n].pop();
    }
    for (int i = 0; i < k; i++) cout << ans[i] << " ";
    


}