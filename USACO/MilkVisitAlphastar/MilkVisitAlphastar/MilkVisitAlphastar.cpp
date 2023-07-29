#include <bits/stdc++.h>
using namespace std;

vector <bool> visited;
vector <char> farms;
int ans = 0, curAi, curBi, curCi, curAns = 0;
//this code is definitelly too slow
void dfs(int curNode, bool tempAns, vector <bool>& visited){
	
	if (farms[curNode] == curCi){
		tempAns = true;
	}
	visited[curNode] = true;

}
int main(){
	int n, m;
	cin >> n >> m;
	farms.resize(n + 1); visited.resize(n + 1);
	for (int i = 1; i <= n; i++){
		char t; cin >> t;
		farms[i] = t;
	}
	for (int i = 0; i < n; i++){
		cin >> curAi >> curBi >> curCi;
		dfs(curAi, false, visited);
		cout << curAns; curAns = 0;
	}	

}