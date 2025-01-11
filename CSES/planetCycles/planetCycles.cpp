#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    int n;
    cin >> n;
    //functional graph, each node has one outgoing edge
    //first have to mark the nodes which are actually in a cycle
    vector <vector <int>> graph(n + 1), rgraph(n + 1);
    vector <int> visited(n + 1, 0), cycleNum(n + 1, 0), ans(n + 1, 0);
    for (int i = 1; i <= n; i++){
        int tt;
        cin >> tt;
        graph[i].push_back(tt);
        rgraph[tt].push_back(i);
    }
    int curComp = 2;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            set <int> nodesVis;
            queue <int> nodes;
            nodes.push(i);
            while (!nodes.empty()){
                int curNode = nodes.front();
                nodesVis.insert(curNode);
                nodes.pop();
                visited[curNode]++;
                for (int nextNode : graph[curNode]){
                    if (visited[nextNode] && nodesVis.count(nextNode)){
                        //cycle woohoo  
                        int curAmt = 0;
                        queue <int> cycle;
                        cycle.push(nextNode);
                        //visited[nextNode]++;
                        while (!cycle.empty()){
                            curAmt++;
                            int cycNode = cycle.front();
                            cycle.pop();
                            visited[cycNode] = curComp;
                            for (int ncycNode : graph[cycNode]){
                                if (visited[ncycNode] != curComp){
                                    cycle.push(ncycNode);
                                } else{
                                    cycleNum[curComp++] = curAmt;
                                }
                            }
                        }
                    } else if (!visited[nextNode]){
                        nodes.push(nextNode);
                    }
                }
            }
        }
    }
    //now all the nodes in a cycle are marked each have id which rep. # of nodes in cycle
    
    for (int i = 1; i <= n; i++){
        if (!ans[i] && visited[i] >= 2){
            queue <pair <int, int>> q;
            q.push({i, cycleNum[visited[i]]});

            while (!q.empty()){
                auto cur = q.front();
                q.pop();
                ans[cur.first] = cur.second;
                for (int next : rgraph[cur.first]){
                    if (ans[next] == 0){
                        if (visited[next] >= 2){
                            q.push({next, cur.second});
                        } else q.push({next, cur.second + 1});
                        
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

}