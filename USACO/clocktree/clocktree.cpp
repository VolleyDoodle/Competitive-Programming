#include <bits/stdc++.h>
using namespace std;
int n;
vector <vector <int>> tree;
vector <int> clockVal, clockValcopy;

void dfs(int curNode, int parent){
    for (auto child : tree[curNode]){
        if (child != parent){
            clockVal[child]++;
            if (clockVal[child] > 12) {clockVal[child]%=12;}
            dfs(child, curNode);
            
            //still currently at curNode
            
        }
        
    }
    if (curNode == parent) {return;}
    if (clockVal[parent] == clockVal[curNode]){ //reach 12, end up at curNode
        clockVal[curNode] = 12; clockVal[parent] = 1;
    }
    else if (clockVal[curNode] - 1 == clockVal[parent]){ //child will get 12, but curNode at 1
        clockVal[curNode] = 12; clockVal[parent] = 12;
    }
    else{
        clockVal[parent]+= (12 - clockVal[curNode]) + 1;
        if (clockVal[parent] > 12) {clockVal[parent]%=12;}
        clockVal[curNode] = 12;
    } 

}
int main(){
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    cin >> n;
    clockVal.resize(n + 1); clockValcopy.resize(n + 1); 
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> clockVal[i];
        clockValcopy[i] = clockVal[i];
    }
    for (int i = 1; i < n; i++){
        int t1,t2;
        cin >> t1 >> t2;
        tree[t1].push_back(t2);
        tree[t2].push_back(t1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        //go to leaves of tree and proceed to cut
        dfs(i, i);
        if (clockVal[i] == 1 || clockVal[i] == 12){
            ans++;
        }
        clockVal = clockValcopy;
    }
    cout << ans;
}