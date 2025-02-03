#include <bits/stdc++.h>
using namespace std;
//basically just successor graph
//have array of connected compenent which stores # of nodes in it

int charToIndex(char c){
    if (islower(c)){
        return c - 'a';
    } else{
        return c - 'A' + 26;
    }
}
void solve(){
    //might be the most fucking annoyiing problem to implemenet
    //its aight tho
    //
    int ans = 0, cycCount = 0;
    string c1, c2;
    cin >> c1 >> c2;
    bool pos = true;
    vector <set<int>> graph(52);
    vector <set <int>> temp(52);
    set <char> check;
    map <int, bool> cycles;
    for (int i = 0; i < c1.size(); i++){
        temp[charToIndex(c1[i])].insert(charToIndex(c2[i]));
        if (temp[charToIndex(c1[i])].size() > 1) pos = false;
        check.insert(c2[i]);
        if (c1[i] == c2[i] || graph[charToIndex(c1[i])].count(charToIndex(c2[i]))) continue;
        graph[charToIndex(c1[i])].insert(charToIndex(c2[i]));
        ans++;
        
    }
    if (!pos || (check.size() == 52 && c1 != c2)){
        cout << -1;
        return;
    }
    vector <int> visited(52, 0);
    for (int i = 0; i < 52; i++){
        //stupid ahh bfs
        if (!visited[i]){
            set <int> s;
            queue <int> q1;
            q1.push(i);
            s.insert(i);
            while (!q1.empty()){
                int cur = q1.front(); q1.pop();
                visited[cur]++;
                if (graph[cur].empty()) continue;
                int nxt = *(graph[cur].begin());
                if (visited[nxt] && s.count(nxt)){
                    //boom cycle
                    cycles[cycCount + 2] = false;
                    queue <int> q2;
                    q2.push(nxt);
                    while (!q2.empty()){
                        int cur2 = q2.front(); q2.pop();
                        visited[cur2] = cycCount + 2;
                        if (visited[*(graph[cur2].begin())] == 1){
                            q2.push(*(graph[cur2].begin()));
                        }
                    }
                    cycCount++;
                } else if (!visited[nxt]) q1.push(nxt);
            }
        }
    }
    //now all cycles marked with two
    cycles[1] = true;
    for (int i = 0; i < 52; i++){
        if (!graph[i].empty() && !cycles[visited[*(graph[i].begin())]] && visited[i] == 1){
            cycCount--;
            cycles[visited[*(graph[i].begin())]] = true;
        }
    }
    cout << ans + cycCount;

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