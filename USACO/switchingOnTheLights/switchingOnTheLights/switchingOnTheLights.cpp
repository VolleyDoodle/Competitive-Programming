#include <bits/stdc++.h>
using namespace std;
int n, m;
bool bGrid[102][102], curVisited[102][102];
vector <vector <vector <pair <int, int>>>> graph;
//unordered_map <pair <int, int>, graphtor <pair <int, int>>> graph;
int ans = 1;
void dfs(int xNode, int yNode){
	
	curVisited[xNode][yNode] = true;
	for (auto curNode : graph[xNode][yNode]){
		if (!bGrid[curNode.first][curNode.second]){
			for (int i = 0; i <= n; i++){
				fill(curVisited[i], curVisited[i] + n, 0);
			}
			ans++;
		}
		bGrid[curNode.first][curNode.second] = true;
		
	}
	
	if (!curVisited[xNode][yNode + 1] && bGrid[xNode][yNode + 1]){
		dfs(xNode, yNode + 1);
	} if (!curVisited[xNode][yNode - 1] && bGrid[xNode][yNode - 1]){
		dfs(xNode, yNode - 1);
	} if (!curVisited[xNode + 1][yNode] && bGrid[xNode + 1][yNode]){
		dfs(xNode + 1, yNode);
	} if (!curVisited[xNode - 1][yNode] && bGrid[xNode - 1][yNode]){
		dfs(xNode - 1, yNode);
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	graph.resize(n + 2);
	for (int i = 0; i <= n; i++){
		graph[i].resize(n + 2);
	}
	for (int i = 0; i < m; i++){
		int xf, yf, xs, ys;
		cin >> xf >> yf >> xs >> ys;
		graph[xf][yf].push_back({xs, ys});
	}
	bGrid[1][1] = true;
	dfs(1, 1);
	cout << ans;

	

}

